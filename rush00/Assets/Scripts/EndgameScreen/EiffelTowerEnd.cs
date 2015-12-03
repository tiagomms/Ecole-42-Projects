using UnityEngine;
using System.Collections;

public class EiffelTowerEnd : MonoBehaviour {
	// Use this for initialization
	void Start () {
		transform.localScale = new Vector3 (150,150,60);
	}
	
	// Update is called once per frame
	void Update () {
		if (transform.localScale.x <= 10)
			transform.localScale = new Vector3 (150,150,60);
		transform.localScale -= new Vector3 (5, 5, 0);
	}
}
