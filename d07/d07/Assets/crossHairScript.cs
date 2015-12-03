using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class crossHairScript : MonoBehaviour {
	
	public	bool		targetAcquired = false;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (targetAcquired) {
			gameObject.GetComponent<Image>().color = Color.red;
		}
		else
			gameObject.GetComponent<Image>().color = Color.white;

	}
}
