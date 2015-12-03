using UnityEngine;
using System.Collections;

public class fieldOfViewCam : MonoBehaviour {

	private float fieldOfView = 60.0f;
	private float zoomSpeed = 2.0f;
	private float minZoom = 1.0f;
	private float maxZoom = 100.0f;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey ("z")) {
			fieldOfView += zoomSpeed;
		}
		if (Input.GetKey ("c")) {
			fieldOfView -= zoomSpeed;
		}
		if (Input.GetKey ("x")) {
			fieldOfView = 60f;
		}
		fieldOfView = Mathf.Clamp (fieldOfView, minZoom, maxZoom);
		gameObject.GetComponent<Camera> ().fieldOfView = fieldOfView;
	}
}
