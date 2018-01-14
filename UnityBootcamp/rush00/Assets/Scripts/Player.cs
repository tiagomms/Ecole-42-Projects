using UnityEngine;
using System.Collections;
using UnityEditor;
using UnityEngine.UI;

public class Player : MonoBehaviour {
	public     	int    		hp;
	private 	float  		speed = 0.3f;
	public		GameObject	currentWeapon;
	[HideInInspector]public		bool		hasWeapon = false;
	[HideInInspector]public		Vector3		moveDirection;
	private		bool			canShoot = true;
	[HideInInspector]public		bool			isPlayerDead = false;





	void Start () {

	}

	void OnTriggerEnter2D(Collider2D collider) {
		if (collider.gameObject.tag == "Weapon" && !this.currentWeapon) {

			this.currentWeapon = collider.gameObject;
			this.currentWeapon.GetComponent<Weapon>().shooterTag = gameObject.tag;

			Debug.Log ("got weapon: " + collider.gameObject.name); // while there is no text
			currentWeapon.GetComponent<Weapon> ().ActivateWeaponSounds ();
			currentWeapon.transform.parent = gameObject.transform;
			currentWeapon.transform.localPosition = new Vector3(-0.1f, -0.28f, 0f);
			currentWeapon.transform.localRotation = Quaternion.identity;
			currentWeapon.transform.localScale = new Vector3 (1f, 1f, 1f);

		}
	}

	public	void	PlayerDead() {
		isPlayerDead = true;
	}

	public GameObject getCurrentWeapon() {
		return currentWeapon;
	}

	public void GotWeapon() {
		hasWeapon = true;
	}

	IEnumerator FireIsShot() {

		if (Input.GetMouseButtonDown (0) && currentWeapon && hasWeapon && canShoot) {
			currentWeapon.GetComponent<Weapon> ().shotFire ();
			canShoot = false;
			yield return new WaitForSeconds(currentWeapon.GetComponent<Weapon>().fireRate);

			canShoot = true;
		}
	}

	void Update () {
		if (isPlayerDead)
			return;
		moveDirection = Camera.main.ScreenToWorldPoint(Input.mousePosition) - gameObject.transform.position; 
		if (moveDirection != Vector3.zero) 
		{
			float angle = Mathf.Atan2(moveDirection.y, moveDirection.x) * Mathf.Rad2Deg +90;
			transform.rotation = Quaternion.AngleAxis(angle, Vector3.forward);
		}
		if (Input.GetKey (KeyCode.W)) {
			transform.Translate(Vector2.up* speed, 0);
		} else if (Input.GetKey (KeyCode.S)) {
			transform.Translate(- Vector2.up * speed, 0);
		}
		if (Input.GetKey (KeyCode.A)) {
			transform.Translate(- Vector2.right *speed, 0);
		} else if (Input.GetKey (KeyCode.D)) {
			transform.Translate(Vector2.right* speed, 0);
		}

		StartCoroutine("FireIsShot");

		if (Input.GetMouseButtonDown (1) && hasWeapon && currentWeapon) {
			if (!hasWeapon)
				return;
			currentWeapon.GetComponent<Weapon>().discardWeapon();
			hasWeapon = false;
		}

	}
	
	
}

