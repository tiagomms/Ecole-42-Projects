using UnityEngine;
using System.Collections;

public class PapersGot : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}

	void OnTriggerStay(Collider other)
	{
		if (other.gameObject.tag == "Player" && other.gameObject.GetComponent<PlayerScript> ().GotKeyChain) {
			if (Input.GetKeyUp ("e"))
			{
				Application.LoadLevel("ex02");
			}
		}

	}

	// Update is called once per frame
	void Update () {

	}
}
