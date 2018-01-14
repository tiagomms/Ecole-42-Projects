using UnityEngine;
using System.Collections;

public class LastPlayerSighting : MonoBehaviour {

	public Vector3	resetPosition;
	public Vector3	position;

	// Use this for initialization
	void Start () {
		resetPosition = gameObject.transform.position;
		position = resetPosition; //?
	}

}
