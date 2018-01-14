using UnityEngine;
using System.Collections;

public class GetPapersText : MonoBehaviour {

	public GameObject Door;

	// Use this for initialization
	void Start () {
	
	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.tag == "Player") {
			if (!Door)
				other.gameObject.GetComponent<PlayerScript>().GuideText.text = "Use E to get the papers and restart.";
		}
	}
	
	void OnTriggerExit(Collider other) {
		if (other.gameObject.tag == "Player") {
			other.gameObject.GetComponent<PlayerScript>().GuideText.text = "";
		}
	}

	// Update is called once per frame
	void Update () {
	
	}
}
