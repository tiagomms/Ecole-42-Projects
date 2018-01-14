using UnityEngine;
using System.Collections;

public class movePlayer : MonoBehaviour {

	private float 		speed = 0.5f;
	private float		timer = 0.0f;
	public	float		currentVelocity = 0.0f;
	private Vector3		savedPosition;

	
	// Use this for initialization
	void Start () {
				
	}
	
	// Update is called once per frame
	void Update () {
		if (GetComponent<PlayerScript> ().imDead)
			return;
		savedPosition = gameObject.transform.position;
		if (Input.GetKey ("a")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.left, speed * Time.deltaTime);
			gameObject.transform.position -= gameObject.transform.right * speed * timer;
			timer += Time.deltaTime;
		}
		if (Input.GetKey ("d")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.right, speed * Time.deltaTime);
			gameObject.transform.position += gameObject.transform.right * speed * timer;
			timer += Time.deltaTime;
		}
		if (Input.GetKey ("s")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.back, speed * Time.deltaTime);
			gameObject.transform.position -= gameObject.transform.forward * speed * timer;
			timer += Time.deltaTime;
		}
		if (Input.GetKey ("w")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.forward, speed * Time.deltaTime);
			gameObject.transform.position += gameObject.transform.forward * speed * timer;
			timer += Time.deltaTime;
		}
		currentVelocity = Vector3.Magnitude (gameObject.transform.position - savedPosition) / Time.deltaTime;
		gameObject.GetComponent<PlayerScript> ().playerVelocity = currentVelocity;
		if ((Input.GetKeyUp ("a") || Input.GetKeyUp ("d") || Input.GetKeyUp ("s") || Input.GetKeyUp ("w")) && !Input.anyKey)
			timer = 0.0f;
	}
}
