using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class LightDiscretion : MonoBehaviour {

	public GameObject 	fan;
	private		int AvoidsOrNot;
	// Use this for initialization
	void Start () {
		AvoidsOrNot = Random.Range (0, 2);
	}

	void	OnTriggerStay(Collider obj) {
		if (obj.gameObject.tag == "Player") {
			obj.gameObject.GetComponent<PlayerScript> ().inTheShadows = false;
			AvoidsOrNot = Random.Range (0, 3);
			if (fan.GetComponent<fanWork> ().behaviourFan) {
				if (AvoidsOrNot == 2) {
					obj.gameObject.GetComponent<PlayerScript> ().inTheShadows = true;
				}
			}
		}
	}

	void	OnTriggerExit(Collider obj)
	{
		if (obj.gameObject.tag == "Player")
			obj.gameObject.GetComponent<PlayerScript> ().inTheShadows = true;
	}

	// Update is called once per frame
	void Update () {
		
	}
}
