using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class spawnEnemy : MonoBehaviour {

	public	GameObject[]		LambentSpawningOptions;
	[HideInInspector]public	List<GameObject>	currentLambent;
	public	float				minSpawningTime = 30f;
	public	float				maxSpawningTime = 90f;
	
	private bool				isInstantiationTime = false;
	private float				currentSpawningTime = 0.0f;

	// Use this for initialization
	void Start () {
	
	}

	IEnumerator spawnNewOne() {
		if (currentSpawningTime == 0f)
			currentSpawningTime = Random.Range (minSpawningTime, maxSpawningTime);
		yield return new WaitForSeconds (currentSpawningTime);
		isInstantiationTime = false;
		currentSpawningTime = 0f;

	}

	void Spawn() {
		if (!isInstantiationTime) {
			currentLambent.Add ((GameObject)Instantiate (LambentSpawningOptions [Random.Range (0, 2)], transform.position, Quaternion.identity));
			isInstantiationTime = true;
		}
	}

	// Update is called once per frame
	void Update () {
		
	}
//	if (life <= 0) { //Dead
//		Dead ();
//		return;
//	}
	
	
	void LateUpdate() {
		Spawn ();
		if (currentLambent.Count == 0) {
			StartCoroutine("spawnNewOne");
		}
	}
}
