using UnityEngine;
using System.Collections;

public class CamTitle : MonoBehaviour {
//	ExitButtonScript exit;
//	StartButtonScript start;
	Camera cam;
	float duration;
	Color color1;
	Color color2;
	// Use this for initialization
	void Start () {
//		exit = gameObject.GetComponent<ExitButtonScript> ();
//		start = gameObject.GetComponent<StartButtonScript> ();
		cam = Camera.main.GetComponent<Camera>();
		cam.clearFlags = CameraClearFlags.SolidColor;
		color1 = Color.black;
		color2 = Color.white;
		duration = 0;
	}
	// Update is called once per frame
	void Update () {
		if (duration >= 1) {
//			float t = Mathf.PingPong(Time.time, duration) / duration;
			cam.backgroundColor = Color.Lerp(color1, color2, Time.time);
			duration=0;
		}
		duration += Time.deltaTime;
	}
}
