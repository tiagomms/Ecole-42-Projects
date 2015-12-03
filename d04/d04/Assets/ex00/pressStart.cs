using UnityEngine;
using System.Collections;

public class pressStart : MonoBehaviour {

	public AudioSource		startSong;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown("return"))
		{
			startSong.Play();
			Application.LoadLevel("DataSelect");
		}
	}
}
