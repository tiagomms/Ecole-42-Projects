using UnityEngine;
using System.Collections;

public class movePlayer : MonoBehaviour {

	private float speed = 50.0f;
	
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey ("q")) {
			//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.down, speed * Time.deltaTime);
			gameObject.transform.position -= gameObject.transform.up * speed * Time.deltaTime;
		}
		if (Input.GetKey ("e")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.up, speed * Time.deltaTime);
			gameObject.transform.position += gameObject.transform.up * speed * Time.deltaTime;
		}
		if (Input.GetKey ("a")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.left, speed * Time.deltaTime);
			gameObject.transform.position -= gameObject.transform.right * speed * Time.deltaTime;
		}
		if (Input.GetKey ("d")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.right, speed * Time.deltaTime);
			gameObject.transform.position += gameObject.transform.right * speed * Time.deltaTime;
		}
		if (Input.GetKey ("s")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.back, speed * Time.deltaTime);
			gameObject.transform.position -= gameObject.transform.forward * speed * Time.deltaTime;
		}
		if (Input.GetKey ("w")) {
//			gameObject.transform.position = Vector3.MoveTowards(transform.position, transform.position + Vector3.forward, speed * Time.deltaTime);
			gameObject.transform.position += gameObject.transform.forward * speed * Time.deltaTime;
		}
	}
}
