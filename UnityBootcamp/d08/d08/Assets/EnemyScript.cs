using UnityEngine;
using System.Collections;

public class EnemyScript : MonoBehaviour {

	public	int			life = 3;
	public	float		attackingDistance = 2f;
	public	MayaScript	player;

	private Transform	_enemyTransform;
	private	Animator	_enemyAnim;
	private NavMeshAgent _agent;
	private float		_timer = 0.0f;
	private bool		_doItOnce = false;

	// Use this for initialization
	void Start () {
		player = FindObjectOfType<MayaScript> ();
		_enemyAnim = GetComponent<Animator> ();
		_agent = GetComponent<NavMeshAgent> ();
		_enemyTransform = transform;
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
		_enemyTransform.LookAt (player.transform.position);
		//damage opponent
	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.tag == "Player") {
			_doItOnce = false;
			Run();
		}
	}

	// Update is called once per frame
	void Update () {
		if (player.GetComponent<MayaScript> ().isMayaDead)
			return;
		//if is dead animation
		if ((_enemyAnim.GetBool ("isRunning") && Vector3.Magnitude (_enemyTransform.position - player.transform.position) < 2)) {
			_doItOnce = false;
			Attack ();
		} else if (_enemyAnim.GetBool ("isAttacking")) {
			Attack ();
		}
		else if (_enemyAnim.GetBool ("isRunning")) {
			Run ();
		} else {
			_doItOnce = false;
			Idle ();
		}
	}
}
