using UnityEngine;
using System.Collections;

public class explosionEnd : MonoBehaviour {

	[HideInInspector]public	float	explosion;

	// Use this for initialization
	void Start () {
		explosion = GetComponent<ParticleSystem> ().duration;
	}

	IEnumerator endExplosion() {
		yield return new WaitForSeconds (explosion);
		Destroy (gameObject);
	}

	// Update is called once per frame
	void Update () {
		StartCoroutine ("endExplosion");
	}
}
