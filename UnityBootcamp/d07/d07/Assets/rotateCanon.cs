using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class rotateCanon : MonoBehaviour {

	public float 		sensitivityX = 10F;
	public GameObject	gunShot;
	public GameObject	missileShot;
	public AudioSource	gunSound;
	public AudioSource	missileSound;
	public int			ammoMissile = 8;
	public Text 		ammountMissile;
	public GameObject	crossHair;
	private	RaycastHit	hit;
	private float		previousPos;
	[HideInInspector]public GameObject shooter;
	
	void Start() {
		shooter = gameObject.transform.parent.gameObject;
	}


	// Update is called once per frame
	void Update () {
		transform.Rotate(0, Input.GetAxis("Mouse X") * sensitivityX, 0);
		//Debug.DrawRay (transform.position + gameObject.transform.forward, gameObject.transform.forward * 50.0f,  Color.green);
		if (Input.GetMouseButtonUp (0)) {
			gunSound.Play ();
			GameObject.Instantiate (gunShot, transform.position, Quaternion.LookRotation(transform.forward));
			gunShot.GetComponent<shooting>().tankTag = gameObject.tag;
			gunShot.GetComponent<shooting> ().shooter = shooter;
		} else if (Input.GetMouseButtonUp (1) && ammoMissile > 0) {
			ammoMissile--;
			missileSound.Play ();
			GameObject.Instantiate (missileShot, transform.position, Quaternion.LookRotation(transform.forward));
			missileShot.GetComponent<shooting>().tankTag = gameObject.tag;
			missileShot.GetComponent<shooting> ().shooter = shooter;
		}
		ammountMissile.text = "X" + ammoMissile.ToString ();
		if (Physics.SphereCast (gameObject.transform.position + gameObject.transform.forward, 2f, gameObject.transform.forward, out hit,
		                     Mathf.Infinity)) {
			if (hit.collider.tag == "Enemy" && !hit.collider.isTrigger) {
				crossHair.GetComponent<crossHairScript> ().targetAcquired = true;
			} else {
				crossHair.GetComponent<crossHairScript> ().targetAcquired = false;
			}
		} else {
			crossHair.GetComponent<crossHairScript> ().targetAcquired = false;
		}
	}
}
