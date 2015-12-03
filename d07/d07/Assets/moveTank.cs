using UnityEngine;
using System.Collections;

public class moveTank : MonoBehaviour {

	private Rigidbody 	rb;
	private bool		isShift = false;
	public	float		normalAngularSpeed = 6f;
	public	float		normalSpeed = 9f;
	private	float		angularSpeed;
	private	float		speed;
	public	float		rechargeTime = 7f;
	public	float		shiftTime = 5f;
	public	bool		wasPlayerSpotted = false;
	public	AudioSource	normalSong;
	public	AudioSource	panicSong;


	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody> ();
		Physics.gravity = new Vector3 (0f, -rb.mass * 1.5f, 0);
		angularSpeed = normalAngularSpeed;
		speed = normalSpeed;
	}

	IEnumerator RechargeTime() {
		angularSpeed = normalAngularSpeed;
		speed = normalSpeed;
		yield return new WaitForSeconds (rechargeTime);
		isShift = false;
	}

	IEnumerator ShiftKeyPress() {
		angularSpeed = normalAngularSpeed * 2f;
		speed = normalSpeed * 2.5f;
		yield return new WaitForSeconds (shiftTime);
		isShift = true;
	}

	void	playBackgroundMusic() {
		if (!wasPlayerSpotted) {
			if (panicSong.isPlaying)
				panicSong.Stop ();
			if (!normalSong.isPlaying)
				normalSong.Play ();
		} else {
			if (normalSong.isPlaying)
				normalSong.Stop ();
			if (!panicSong.isPlaying)
				panicSong.Play ();
		}
	}

	// Update is called once per frame
	void Update () {
		playBackgroundMusic ();

		if (Input.GetKey ("a")) {
			rb.angularVelocity = -Vector3.up * angularSpeed;
		} else if (Input.GetKey ("d")) {
			rb.angularVelocity = Vector3.up * angularSpeed;
		}

		if (Input.GetKey ("w")) {
			gameObject.transform.position += gameObject.transform.forward * speed * Time.deltaTime;
		} else if (Input.GetKey ("s")) {
			gameObject.transform.position -= gameObject.transform.forward * speed * Time.deltaTime;
		}
		if (Input.GetKeyDown ("space"))
			rb.AddForce (Vector3.up * rb.mass * 20, ForceMode.Impulse);
		if (!isShift) {
			if (Input.GetKey (KeyCode.LeftShift)) {
				StartCoroutine ("ShiftKeyPress");
			} else {
				StopCoroutine("ShiftKeyPress");
				angularSpeed = normalAngularSpeed;
				speed = normalSpeed;
			}
		} else {
			StartCoroutine("RechargeTime");
		}
		if (!Input.anyKey) {
//			rb.velocity = Vector3.zero;
			rb.angularVelocity = Vector3.zero;
		}

	}
}
