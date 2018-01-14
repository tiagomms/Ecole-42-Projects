using UnityEngine;
using System.Collections;

public class fanWork : MonoBehaviour {

	[HideInInspector]	public	bool		behaviourFan = false;
	private	bool		clicked = false;
	private	bool		isDone = false;
	public	AudioSource	fanSound;

	// Use this for initialization
	void Start () {
		gameObject.GetComponent<ParticleSystem> ().enableEmission = false;
		behaviourFan = gameObject.GetComponent<ParticleSystem> ().enableEmission;
	}

	IEnumerator activateSound() {
		fanSound.Play ();
		yield return new WaitForSeconds (1.0f);
		clicked = false;
		isDone = true;
		fanSound.Stop ();
	}

	void OnTriggerStay(Collider other)
	{
		if (other.gameObject.tag == "Player") {
			if (Input.GetKeyUp ("e")) {
				if (!clicked) {
					behaviourFan = !gameObject.GetComponent<ParticleSystem> ().enableEmission;
					gameObject.GetComponent<ParticleSystem> ().enableEmission = behaviourFan;
					clicked = true;
				}
			}
		}
	}	

	void OnTriggerExit(Collider other)
	{
		if (other.gameObject.tag == "Player") {
			clicked = false;
		}
	}


	// Update is called once per frame
	void Update () {
		if (clicked && !isDone) {
			StartCoroutine("activateSound");
		}
	}
}
