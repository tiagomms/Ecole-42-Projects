using UnityEngine;
using System.Collections;

public class HackAndSlashCamera : MonoBehaviour {

	public	Transform 	target;
	public	float		minDistance = 4f;
	public	float		minCameraHeight = 6f;
	public	float		maxDistance = 200f;

	private	Transform	_myTransform;
	private RaycastHit	hit;

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

		_myTransform.position = new Vector3 (target.position.x + minDistance, target.position.y + minCameraHeight, target.position.z + minDistance);
		_myTransform.LookAt (target);
		float distance;
		distance = Vector3.Distance (target.position, _myTransform.position);

		if (Physics.Raycast (_myTransform.position, (target.position - _myTransform.transform.position), out hit, distance)) {
			Transform aux = _myTransform;
			while (Physics.Raycast (aux.position, (target.position - aux.transform.position), out hit, distance)) {
				if (hit.collider.gameObject.tag != "terrain") {
					break;
				}
				aux.position = new Vector3 (aux.position.x, aux.position.y + 0.15f, aux.position.z + 0.1f);
				aux.LookAt(target);
				distance = Vector3.Distance (target.position, aux.position);
			}
			_myTransform = aux;
		}

	}

}
