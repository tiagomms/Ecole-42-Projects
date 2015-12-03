using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class AmmoScript : MonoBehaviour {

	public 	float 					speed = 0.0f;
//	public 	GameObject 				shellExplosion;
	private Vector3 				shotDirection;
	private Vector3					direction;
	public bool					isShot = false;
	public bool						hasDirection = false;

	[HideInInspector]public float	timer = 1.5f;
	[HideInInspector]public string	weaponOwner;
	[HideInInspector]public Vector3	targetPos;


	private GameObject				clone;


	void Start() {
//		shellExplosion.GetComponent<SpriteRenderer> ().enabled = false;
	}



	public void gotShotDirection ()
	{
		isShot = true;
		if (!hasDirection) {
			hasDirection = true;
			if (weaponOwner == "Ennemy") {
//				direction = (targetPos - gameObject.transform.position);
				direction = targetPos;
				shotDirection = targetPos - gameObject.transform.position;
				shotDirection.z = 0;
				direction.z = 0f;
				float angle = Mathf.Atan2 (shotDirection.y, shotDirection.x) * Mathf.Rad2Deg;
				transform.localRotation = Quaternion.AngleAxis (angle, Vector3.forward);
			} else {
				shotDirection = Camera.main.ScreenToWorldPoint (Input.mousePosition) - gameObject.transform.position;
				shotDirection.z = 0;
//				direction = Camera.main.ScreenToWorldPoint (Input.mousePosition) - gameObject.transform.position;
				direction = Camera.main.ScreenToWorldPoint (Input.mousePosition);
				direction.z = 0f;
				float angle = Mathf.Atan2 (shotDirection.y, shotDirection.x) * Mathf.Rad2Deg;
				transform.localRotation = Quaternion.AngleAxis (angle, Vector3.forward);
			}
		}
		
	}

	public void gotStab() {
		isShot = true;
		Debug.Log ("gotStab");
	}

	void	OnTriggerEnter2D(Collider2D obj)
	{
//		if (obj.gameObject.tag != "Ennemy") {
//			Debug.Log ("weaponOwner: " + weaponOwner);
//			Debug.Log ("collider tag: " + obj.gameObject.tag);
//			Debug.Log ("isShot: " + isShot);
//			Debug.Log ("collider has Trigger " + obj.isTrigger);
//		}
		if (weaponOwner != obj.gameObject.tag && obj.gameObject.tag != "Weapon" && isShot && !obj.isTrigger) {
			speed = 0f;
			if (obj.gameObject.tag == "Player") 
				obj.gameObject.GetComponent<Player> ().PlayerDead();
			if (obj.gameObject.tag == "Ennemy")
				obj.gameObject.GetComponent<Ennemy> ().EnnemyDied ();

			Destroy (gameObject);

		}

	}
	
	// Update is called once per frame
	void Update () {
		if (isShot) {
			gameObject.transform.position = Vector3.MoveTowards( transform.position, transform.position + shotDirection.normalized, speed * Time.deltaTime * 2f);
//			transform.position += direction * speed * Time.deltaTime;
		} 
		timer -= Time.deltaTime;
		if (timer < 0.0f)
			Destroy (gameObject);
	}

}

//		if (Mathf.Abs(shotDirection.x) < 1.0f && Mathf.Abs(shotDirection.y) < 1.0f)
//			direction = shotDirection;
//		else
