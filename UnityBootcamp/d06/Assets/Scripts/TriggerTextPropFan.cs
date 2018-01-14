using UnityEngine;
using System.Collections;

public class TriggerTextPropFan : MonoBehaviour {

	//private bool	doItOnce = false;
	public GameObject player;

	// Use this for initialization
	void Start () {
	
	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.tag == "Player") {
			if (!this.transform.parent.gameObject.GetComponent<fanWork>().behaviourFan) {
//				GetComponent<PlayerScript>().GuideText.text = "Press E to activate the fan";
				player.GetComponent<PlayerScript>().GuideText.text = "Press E to activate the fan";
			}
		}
	}

	void OnTriggerExit(Collider other) {
		if (other.gameObject.tag == "Player") {
			player.GetComponent<PlayerScript> ().GuideText.text = "";
			player.GetComponent<PlayerScript> ().deletedInitialText = true;
		}
	}

	// Update is called once per frame
	void Update () {
		if (this.transform.parent.gameObject.GetComponent<fanWork>().behaviourFan) {
//			gameObject.GetComponent<PlayerScript>().GuideText.text = " ";
			if (!player.GetComponent<PlayerScript>().deletedInitialText) {
				player.GetComponent<PlayerScript>().GuideText.text = "";
				player.GetComponent<PlayerScript>().deletedInitialText = true;
			}
		}
	}
}
