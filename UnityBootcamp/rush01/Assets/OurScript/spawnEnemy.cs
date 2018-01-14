using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class spawnEnemy : MonoBehaviour {

	public	GameObject[]		LambentSpawningOptions;
	public	GameObject			currentLambent;
	public	float				minSpawningTime = 30f;
	public	float				maxSpawningTime = 90f;
	
	private bool				isInstantiationTime = false;
	private float				currentSpawningTime = 0.0f;
	private float				_timer = 0f;

	// Use this for initialization
	void Start () {

	}

	void OnTriggerEnter(Collider other)
	{
		if (other.gameObject.tag == "Player") {
			if (!currentLambent) {
				spawnNewOne ();
			}
		}
	}


	void spawnNewOne() {

		_timer += Time.deltaTime;
		if (_timer >= currentSpawningTime) {

			currentLambent = ((GameObject)Instantiate (LambentSpawningOptions [Random.Range (0, LambentSpawningOptions.Length)], transform.position, Quaternion.identity));
			_timer = 0f;
			isInstantiationTime = true;
			currentSpawningTime = Random.Range (minSpawningTime, maxSpawningTime);
		}
	}

	// Update is called once per frame
	void Update () {

	}

}
