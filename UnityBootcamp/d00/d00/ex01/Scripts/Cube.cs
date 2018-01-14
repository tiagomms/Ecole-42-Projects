using UnityEngine;
using System.Collections;

public class Cube : MonoBehaviour {

	private float	speed;
	public 	int  	minSpeed = 1;
	public 	int  	maxSpeed = 11;

	// Use this for initialization
	void Start () {
		speed = Random.Range (minSpeed, maxSpeed) / 10.0f;
	}
	
	// Update is called once per frame
	void Update () {
		transform.Translate (0, -speed * Time.deltaTime, 0);
	}
}
