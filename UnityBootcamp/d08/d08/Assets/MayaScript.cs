using UnityEngine;
using System.Collections;

public class MayaScript : MonoBehaviour {

	public	int			life = 100;
	public	float		attackingDistance = 4f;

	public	Camera		camera;
	
	private Transform	_mayaTransform;
	private	Vector3		_moveTo;
	private Vector3		_clickedPosition;
	private	Animator	_mayaAnim;
	private NavMeshAgent _agent;
	private float		_timer = 0.0f;
	[HideInInspector]public	bool		isMayaDead = false;


	// Use this for initialization
	void Start () {
		_mayaTransform = transform;
		_mayaAnim = GetComponent<Animator> ();
		_agent = GetComponent<NavMeshAgent> ();
	}

	void Idle() {
		_mayaAnim.SetBool ("isIdle", true);
		_mayaAnim.SetBool ("isRunning", false);
		_mayaAnim.SetBool ("isAttacking", false);
		_timer = 0f;

	}

	void Run() {
		_mayaAnim.SetBool ("isIdle", false);
		_mayaAnim.SetBool ("isRunning", true);
		_mayaAnim.SetBool ("isAttacking", false);
		_timer = 0f;
		_agent.SetDestination(_clickedPosition);
	}

	void Attack() {
		_mayaAnim.SetBool ("isIdle", false);
		_mayaAnim.SetBool ("isRunning", false);
		_mayaAnim.SetBool ("isAttacking", true);
		_timer = 0f;
		_mayaTransform.LookAt(_clickedPosition);
		//damage opponent
	}

	void Dead() {
		if (!isMayaDead) {
			_timer = 0f;
			isMayaDead = true;
			_mayaAnim.SetInteger ("life", 0);
		}
		if (_timer >= _mayaAnim.GetCurrentAnimatorStateInfo (0).normalizedTime * 2 && 
		    _mayaAnim.GetCurrentAnimatorStateInfo (0).IsName("Death")) {
			Application.LoadLevel("ex01");
		} else {
			_timer += Time.deltaTime;
		}
	}

	void	AfterTheAttack() {
		if (_mayaAnim.GetBool ("isAttacking")) {
			if (_timer >= _mayaAnim.GetCurrentAnimatorStateInfo (0).normalizedTime &&
			    _mayaAnim.GetCurrentAnimatorStateInfo (0).IsName("AttackMaya")) {
				Idle ();
			} else {
				_timer += Time.deltaTime;
			}
		}
	}

	void StopRunningPlayer() {
		if (_mayaAnim.GetBool ("isRunning")) {
			if (Vector3.SqrMagnitude (_mayaTransform.position - _clickedPosition) < 1f)
				Idle ();
		}
	}

	void CourseOfActionAfterMouseClick () {
		if (Input.GetMouseButtonDown (0)) {
			RaycastHit objectClicked;
			Ray ray = camera.ScreenPointToRay(Input.mousePosition);
			if (Physics.Raycast(ray, out objectClicked)) {
				_clickedPosition = objectClicked.point;
				if (objectClicked.collider.gameObject.tag == "Enemy" && 
				    Vector3.Magnitude(_mayaTransform.position - _clickedPosition) < attackingDistance) 
				{
					Attack();
				} 
				else 
				{
					Run ();
				}
			}
		} 
	}

	// Update is called once per frame
	void Update () {
		if (life <= 0) { //Dead
			Dead ();
			return;
		}
		CourseOfActionAfterMouseClick ();
		StopRunningPlayer ();
		AfterTheAttack ();
	}
}
