using UnityEngine;
using System.Collections;

public class PlayerScript_ex00 : MonoBehaviour {
	
	private Rigidbody2D		rb;

	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody2D> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (gameObject.tag == "Player") {
			if (Input.GetKey ("left")) {
				transform.Translate(-Time.deltaTime, 0, 0);
			}
			if (Input.GetKey ("right")) {
				transform.Translate(Time.deltaTime, 0, 0);
			}
			if (Input.GetKeyDown ("space"))
			{
				rb.AddForce(new Vector2(0, 10), ForceMode2D.Impulse);
			}
		}
	}
}
