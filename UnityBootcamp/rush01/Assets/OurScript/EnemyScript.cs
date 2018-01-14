using UnityEngine;
using System.Collections;

public class EnemyScript : MonoBehaviour {

	public	int			life; // life value depends on level
	public	int 		lifeMax;
	public	MayaScript	player;

	private	float		attackingDistance = 4f;
	
	private Transform	_enemyTransform;
	private	Animator	_enemyAnim;
	private NavMeshAgent _agent;
	private float		_timer = 0.0f;
	private bool		_doItOnce = false;
	private bool 		isSinking = false;
	private int			_enemyPoints;


	public	int			enemyLevel;
	public	int			enemyFOR;
	public	int			enemyAGI;


	//clips - sounds when dead
//	public AudioClip 	deathClip;
//	private AudioSource enemyAudio;

	public	GameObject	healthCube;

	//EnemyXP
	//EnemyLevel & XP

	// Use this for initialization
	void Awake () {
		player = FindObjectOfType<MayaScript> ();
		_enemyAnim = GetComponent<Animator> ();
		_agent = GetComponent<NavMeshAgent> ();
//		enemyAudio = GetComponent <AudioSource> ();
		_enemyTransform = transform;
		gameObject.tag = "Enemy";
		_timer = 0.0f;

		setEnemyAttributes ();
	}

	void	setEnemyAttributes() {
		enemyLevel = player.level;

		lifeMax = 25 + (enemyLevel * 5);
		life = lifeMax;


		_enemyPoints = 19 + player.level;
		int mean = Mathf.RoundToInt (_enemyPoints / 2);

		//set Random AGI and FOR
		enemyAGI = Random.Range (mean - 5, mean + 5);
		enemyFOR = _enemyPoints - enemyAGI;

		//agility set
		_agent.speed = 3 + (enemyAGI / 5);

	}

	public void StartSinking ()
	{
		GetComponent <NavMeshAgent> ().enabled = false;
		GetComponent <Rigidbody> ().isKinematic = true;
		isSinking = true;

		//healthBox Spawn --> for now the magic number is 10
		if (Random.Range (0, Mathf.RoundToInt (player.life / 10) + 1) == 0) {
			GameObject.Instantiate (healthCube, transform.position, Quaternion.identity);
		}

		//ScoreManager.score += scoreValue;
		Destroy (gameObject, 2f);
	}

	void Dead() {
		if (_enemyAnim.GetInteger("Life") != 0) {
			_timer = 0f;
			_enemyAnim.SetInteger ("Life", 0);
			_doItOnce = false;
//			if (!death.isPlaying)
//				death.Play();
		}
		if (_timer >= _enemyAnim.GetCurrentAnimatorStateInfo (0).normalizedTime * 2 &&
		    _enemyAnim.GetCurrentAnimatorStateInfo (0).IsName("DeathEnemy")) {
			_enemyAnim.Stop ();
			StartSinking();
		} else {
			_timer += Time.deltaTime;
		}
	}

	void Idle() {
		if (!_doItOnce) {
			_enemyAnim.SetBool ("isIdle", true);
			_enemyAnim.SetBool ("isRunning", false);
			_enemyAnim.SetBool ("isAttacking", false);
			_timer = 0f;
			_doItOnce = true;
		}
		
	}
	
	void Run() {
		if (!_doItOnce) {
			_enemyAnim.SetBool ("isIdle", false);
			_enemyAnim.SetBool ("isRunning", true);
			_enemyAnim.SetBool ("isAttacking", false);
			_timer = 0f;
			_doItOnce = true;
		}
		_agent.SetDestination(player.transform.position);
	}
	
	void Attack() {
		if (!_doItOnce) {
			_enemyAnim.SetBool ("isIdle", false);
			_enemyAnim.SetBool ("isRunning", false);
			_enemyAnim.SetBool ("isAttacking", true);
			_timer = 0f;
			_doItOnce = true;
		}

		if (Vector3.Magnitude (_enemyTransform.position - player.transform.position) >= attackingDistance)
		{
			_doItOnce = false;
			Run ();
		}
		else {
			_enemyTransform.LookAt (player.transform.position);
			_timer += Time.deltaTime;
//			if (_timer >= (_enemyAnim.GetCurrentAnimatorStateInfo (0).normalizedTime * 2 * (10 / enemyAGI ))) {
			if (_timer >= (2 * (10 / enemyAGI ))) {
				_timer = 0f;
				player.GetComponent<MayaFunctions>().EnemyAttack(enemyFOR); 
			}
		}
	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.tag == "Player" && life > 0) {
			_doItOnce = false;
			Run ();
		}
	}

	// Update is called once per frame
	void Update () {
		if (player.GetComponent<MayaScript> ().isMayaDead)
			return;

		if (life <= 0) {
			if (isSinking) {
				transform.Translate (-Vector3.up * 0.5f * Time.deltaTime);
			} else 
				Dead ();
			return;
		} else {
			if ((_enemyAnim.GetBool ("isRunning") && Vector3.Magnitude (_enemyTransform.position - player.transform.position) < attackingDistance)) {
				_doItOnce = false;
				Attack ();
			} else if (_enemyAnim.GetBool ("isAttacking")) {
				Attack ();
			} else if (_enemyAnim.GetBool ("isRunning")) {
				Run ();
			} else {
				if (!_enemyAnim.GetBool ("isIdle")) {
					_doItOnce = false;
					Idle ();
				}
			}
		}
	}
}
