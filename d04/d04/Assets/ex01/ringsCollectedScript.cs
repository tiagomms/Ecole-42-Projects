using UnityEngine;
using UnityEngine.UI;
using System.Collections;



public class ringsCollectedScript : MonoBehaviour {
	
	public Text			RingsGUI;
	public Sonic		sonic;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		RingsGUI.text = " x " + sonic.rings.ToString();
	}
}
