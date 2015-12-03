using UnityEngine;
using System.Collections;

public class switchUnit : MonoBehaviour {

	public	AudioSource AccessGranted;
	public	AudioSource AccessDenied;
	public	GameObject	Door;
	public	GameObject	player;
	private bool		doItOnce = false;

	void OnTriggerStay(Collider other) {
		if (other.gameObject.tag == "Player") {
			if (Input.GetKeyUp ("e")) {
				if (other.gameObject.GetComponent<PlayerScript> ().GotKeyChain) {
					player.GetComponent<PlayerScript>().GuideText.text = "Press E to open the door";
					if (!doItOnce) {
						Destroy (Door);
						AccessGranted.Play ();
						doItOnce = true;
					}
				}
				if (!other.gameObject.GetComponent<PlayerScript> ().GotKeyChain && !doItOnce) {
					if (!AccessDenied.isPlaying)
						AccessDenied.Play ();
					player.GetComponent<PlayerScript>().GuideText.text = "Search for the keychain.";
				}
			}
		}
	}

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
