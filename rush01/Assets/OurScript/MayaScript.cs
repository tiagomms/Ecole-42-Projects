using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class MayaScript : MonoBehaviour {
	
	public	int			life;
	public	int			lifeMax = 100; // <= TO INCREASE WITH LEVEL
	public	int			xp = 10;
	public	int			xpToNextLevel = 100; // <= TO INCREASE WITH LEVEL
	public	int			level = 1;

	public	int			talent = 0;

	// STATS
	public	int 		FOR = 10;
	public	int 		AGI = 10;
	public	int 		CON = 10;

	public	float		extraTimer = 1f;

	public	float		attackingDistance = 4f;

	public	Camera		camera;
	
	private Transform						_mayaTransform;
	private	Vector3							_moveTo;
	private Vector3							_clickedPosition;
	[HideInInspector]public	Animator		_mayaAnim;
	[HideInInspector]public NavMeshAgent	_agent;
	private float							_timer = 0.0f;
	private bool							_enemyHasBeenClicked = false;
	public	GameObject						_enemyTraced;
	[HideInInspector]public	bool			isMayaDead = false;

	public List<GameObject>		spellsBought;
	public List<GameObject>		spellsAvailable;
	public int					indexSpell = 0;

	public LayerMask			notGuiLayer;

	public AudioSource			footStep;
	public AudioSource			hurt;
	public AudioSource			death;

	// Use this for initialization
	void Awake () {
		_mayaTransform = transform;
		_mayaAnim = GetComponent<Animator> ();
		_agent = GetComponent<NavMeshAgent> ();
		_enemyTraced = null;
		life = lifeMax;
		extraTimer = 10 / AGI;
	}

	void Dead() {
		if (!isMayaDead) {
			_timer = 0f;
			isMayaDead = true;
			_mayaAnim.SetInteger ("life", 0);
			if (!death.isPlaying)
				death.Play();
		}
		if (_timer >= _mayaAnim.GetCurrentAnimatorStateInfo (0).normalizedTime * 2 && 
		    _mayaAnim.GetCurrentAnimatorStateInfo (0).IsName("Death")) {
			Application.LoadLevel("ex02");
		} else {
			_timer += Time.deltaTime;
		}
	}

	void Idle() {
			_mayaAnim.SetBool ("isIdle", true);
			_mayaAnim.SetBool ("isRunning", false);
			_mayaAnim.SetBool ("isAttacking", false);
			_timer = 0f;
	}

	void startRunning() {
		_mayaAnim.SetBool ("isIdle", false);
		_mayaAnim.SetBool ("isRunning", true);
		_mayaAnim.SetBool ("isAttacking", false);
		_timer = 0f;
	}

	void startAttacking() {	
		_mayaAnim.SetBool ("isIdle", false);
		_mayaAnim.SetBool ("isRunning", false);
		_mayaAnim.SetBool ("isAttacking", true);
		_timer = 0f;
		_mayaTransform.LookAt (_clickedPosition);
		_mayaAnim.CrossFade ("AttackMaya", 0.1f);
	}

	void whileRunning() {
		if (_mayaAnim.GetBool ("isRunning")) {
			if (!footStep.isPlaying)
				footStep.Play ();
			if (!Input.GetMouseButtonUp(0) && Input.anyKey) {
				if (!UnityEngine.EventSystems.EventSystem.current.IsPointerOverGameObject()) {
					Ray ray = camera.ScreenPointToRay(Input.mousePosition);
					RaycastHit objectClicked;
					if (Physics.Raycast(ray, out objectClicked)) {
						_agent.SetDestination(objectClicked.point);
					}
				}
			}
			else if (!_enemyHasBeenClicked) {
				if (Vector3.SqrMagnitude (_mayaTransform.position - _clickedPosition) < 1f) {
					Idle ();
				}
			}
			else {
				fromRunToAttack();
			}
		}
	}
	
	void	fromRunToAttack() {
		if (_enemyHasBeenClicked && _mayaAnim.GetBool ("isRunning")) {
			if (Vector3.Magnitude (_mayaTransform.position - _enemyTraced.transform.position) < attackingDistance) {
				startAttacking ();
			} else {
				_agent.SetDestination (_enemyTraced.transform.position);
			}
		}
	}

	void whileAttacking() {
		if (_mayaAnim.GetBool ("isAttacking") && _enemyHasBeenClicked) {
			_mayaTransform.LookAt(_enemyTraced.transform.position);
			_timer += Time.deltaTime;
			enemyIsDead();
//			if (_timer >= (_mayaAnim.GetCurrentAnimatorStateInfo (0).normalizedTime * 2 * extraTimer)) {
			if (_timer >= (2f * extraTimer)) {
				_timer = 0f;
				GetComponent<MayaFunctions>().MayaAttack(_enemyTraced);
				if (Input.GetMouseButtonUp(0) || !Input.anyKey) {
					_enemyHasBeenClicked = false;
				}
				else {
					_timer += 2f * Time.deltaTime;
				}
			}
		}
	}

	void enemyIsDead() {
		if (!_enemyTraced || _enemyTraced.GetComponent<EnemyScript>().life <= 0) {
			_enemyHasBeenClicked = false;
			_enemyTraced = null;
			xp += 35;
			Idle ();
		}
	}

	void	AfterTheAttack() {
		if (!_enemyHasBeenClicked && _mayaAnim.GetBool ("isAttacking")) {

			if (_timer >= _mayaAnim.GetCurrentAnimatorStateInfo (0).normalizedTime &&
			    _mayaAnim.GetCurrentAnimatorStateInfo (0).IsName("AttackMaya")) {

				Idle ();
			} else {
				_timer += Time.deltaTime;
			}
		}
	}

	void CourseOfActionAfterMouseClick () {

		if (!UnityEngine.EventSystems.EventSystem.current.IsPointerOverGameObject()) {

			_enemyHasBeenClicked = false;
			_enemyTraced = null;

			RaycastHit objectClicked;
			Ray ray = camera.ScreenPointToRay(Input.mousePosition);
			if (Physics.Raycast(ray, out objectClicked)) {
				_clickedPosition = objectClicked.point;
				if (objectClicked.collider.gameObject.tag == "Enemy")
				{
					if (objectClicked.collider.gameObject.GetComponent<EnemyScript>().life > 0) {
						_enemyHasBeenClicked = true;
						_enemyTraced = objectClicked.collider.gameObject;
						if (Vector3.Magnitude (_mayaTransform.position - _enemyTraced.transform.position) < attackingDistance) {
							startAttacking ();
						} else {
							startRunning ();
						}
					}
				}
				else {
					startRunning();
					_agent.SetDestination(_clickedPosition);
				}
			} 
		}
	}

	void OnMouseDrag() {
		enemyIsDead ();
	}

//	void	debugInputMouse() {
//		if (!Input.GetMouseButtonUp (0) && Input.anyKey) {
//
//			Ray ray = camera.ScreenPointToRay(Input.mousePosition);
//			RaycastHit mouseHit;
//			if (Physics.Raycast(ray, out mouseHit)) {
//				Vector3 direction = mouseHit.point - transform.position;
//				Debug.DrawRay(transform.position, direction, Color.green);
//				Debug.Log (direction);
//			}
//			else
//				Debug.Log ("no hit");
//			
//
//		}
//
//	}


	public void cleanList ()
	{
		if (spellsAvailable.Count > 4) {
			spellsAvailable.RemoveRange(4, spellsAvailable.Count - 4);
		}
	}

	public void useSpell() {
		if (Input.GetKeyDown ("1") && spellsAvailable.Count >= 1) {
			spellsAvailable[0].GetComponent<tryIt>().shoot();
		}
		if (Input.GetKeyDown ("2") && spellsAvailable.Count >= 2) {
			spellsAvailable[1].GetComponent<tryIt>().shoot();
		}
		if (Input.GetKeyDown ("3") && spellsAvailable.Count >= 3) {
			spellsAvailable[2].GetComponent<tryIt>().shoot();
		}
		if (Input.GetKeyDown ("4") && spellsAvailable.Count == 4) {
			spellsAvailable[3].GetComponent<tryIt>().shoot();
		}
	}

	// Update is called once per frame
	void Update () {
//		debugInputMouse ();
		if (life <= 0) { //Dead
			Dead ();
			return;
		}

		cleanList ();
		if (xp >= xpToNextLevel) {
			GetComponent<MayaFunctions>().updateAfterLevelUp();
		}

		if (life > lifeMax)
			life = lifeMax;

		if (Input.GetMouseButtonDown (0)) {
			CourseOfActionAfterMouseClick ();
		}
		whileRunning ();
		whileAttacking ();
		AfterTheAttack ();
		useSpell ();
	}
}
