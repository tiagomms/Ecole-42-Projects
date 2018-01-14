using UnityEngine;
using System.Collections;

public class TriggerTextSwitchUnit : switchUnit {

	// Use this for initialization
	private bool isDoorDestroyed = false;

	void Start () {
	
	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.tag == "Player" && !isDoorDestroyed) {
			if (!player.GetComponent<PlayerScript>().GotKeyChain) {
				player.GetComponent<PlayerScript>().GuideText.text = "Search for the keychain.";
			}
			else {

				player.GetComponent<PlayerScript>().GuideText.text = "Press E to open the door";

			}
		}
	}

	void OnTriggerExit(Collider other) {
		if (other.gameObject.tag == "Player") {
			player.GetComponent<PlayerScript>().GuideText.text = "";
		}
	}

	// Update is called once per frame
	void Update () {
		if (player.GetComponent<PlayerScript> ().GotKeyChain) {
			gameObject.GetComponent<SphereCollider> ().center = new Vector3(1f, 1f, 0f);
			gameObject.GetComponent<SphereCollider> ().radius = 2.0f;
		}
		if (!Door && !isDoorDestroyed) {
			player.GetComponent<PlayerScript> ().GuideText.text = "";
			isDoorDestroyed = true;
		}
	}
}
