using UnityEngine;
using System.Collections;

public class EiffelTower : MonoBehaviour {
	// Use this for initialization
	void Start () {
		transform.localScale = new Vector3 (10,10,60);
	}
	
	// Update is called once per frame
	void Update () {
		if (transform.localScale.x >= 150)
			transform.localScale = new Vector3 (10,10,60);
		transform.localScale += new Vector3 (5, 5, 0);
	}
}
