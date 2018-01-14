using UnityEngine;
using System.Collections;

public class teleport : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter2D(Collider2D obj)
	{
		obj.transform.localPosition = new Vector3 (90f, 25f, 10f);
	}
}
