using UnityEngine;
using System.Collections;

public class GetKeyChain : MonoBehaviour {

	public AudioSource keySound;

	void OnTriggerStay(Collider other) {
		if (other.gameObject.tag == "Player") {
			if (Input.GetKeyUp ("e")) {
				other.gameObject.GetComponent<PlayerScript> ().GotKeyChain = true;
				keySound.Play();
				Destroy (gameObject);
			}
		}
	}
}
