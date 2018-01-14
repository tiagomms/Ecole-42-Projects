using UnityEngine;
using System.Collections;

public class HackAndSlashCamera : MonoBehaviour {

	public	Transform 	target;
	public	float		minDistance;
	public	float		cameraHeight;

	private	Transform	_myTransform;

	// Use this for initialization
	void Start () {
		if (target == null)
			Debug.LogWarning ("lack of target");

		_myTransform = transform;
	}
	
	// Update is called once per frame
	void Update () {
		
	}


	//camera adjust after player has adjusted
	void LateUpdate() {
		_myTransform.position = new Vector3 (target.position.x + minDistance, target.position.y + cameraHeight, target.position.z - minDistance);
		_myTransform.LookAt (target);
	}

}
