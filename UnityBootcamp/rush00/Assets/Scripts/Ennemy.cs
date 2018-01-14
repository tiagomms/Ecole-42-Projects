using UnityEngine;
using System.Collections;

public class Ennemy : MonoBehaviour {
	GameObject 				player;
//	GameObject[] 			doors;
	public bool 			alert = false;
	public GameObject 		currentWeapon;
	bool 					canShoot;
	bool					isDead = false;
	[HideInInspector]public		AudioSource	dyingSound;
	public		AudioClip	dyingClip;

	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag ("Player");
//		doors = GameObject.FindGameObjectsWithTag ("Door");
		canShoot = true;

		dyingSound = gameObject.AddComponent<AudioSource>();
		dyingSound.clip = dyingClip;
		currentWeapon.GetComponent<Weapon> ().ActivateWeaponSounds ();
		currentWeapon.transform.parent = gameObject.transform;
		currentWeapon.transform.localPosition = new Vector3(-0.1f, -0.28f, 0f);
		currentWeapon.transform.localRotation = Quaternion.identity;
		currentWeapon.transform.localScale = new Vector3 (1f, 1f, 1f);
		currentWeapon.GetComponent<Weapon> ().shooterTag = gameObject.tag;
	}

	void OnTriggerStay2D(Collider2D obj) {
		if (obj.gameObject.tag == "Player")
			awake (obj.gameObject);
	}

	/*Vector3 nearestDoor(){
		float min;
		foreach (GameObject door in doors) {
			if (door != null){
				if (true){
					Vector3 ret = door.transform.position;
					door = null;
					return ret;
				}
			}
		}
	}*/
	void awake(GameObject player){
		if (!alert) {
			Vector3 triggerVector = player.transform.position - transform.position;
			triggerVector.z = 0;
			RaycastHit2D[] ray = Physics2D.RaycastAll (transform.position, triggerVector.normalized);
			alert = true;
			if (ray [0].collider.gameObject.tag == "Player") {
				return;
			} else {
				for (int i = 1; i < ray.Length; i++) {
					if (ray [i].collider.gameObject.tag == "Door" || ray [i].collider.gameObject.tag == "Wall") {
						alert = false;
						break;
					}
					if (ray [i].collider.gameObject.tag == "Player") {
						break;
					}
				}
			}
		}
	}

	IEnumerator FireIsShot() {
		if (canShoot && currentWeapon) {
			currentWeapon.GetComponent<Weapon>().targetPos = player.transform.position;
			currentWeapon.GetComponent<Weapon> ().shotFire ();
			canShoot = false;
			yield return new WaitForSeconds(currentWeapon.GetComponent<Weapon>().fireRate);
			canShoot = true;
		}
	}

	void trackingPlayer() {
		Vector3 moveDirection = player.transform.position - gameObject.transform.position;
		if (moveDirection != Vector3.zero) 
		{
			float angle = Mathf.Atan2(moveDirection.y, moveDirection.x) * Mathf.Rad2Deg + 90f;
			transform.rotation = Quaternion.AngleAxis(angle, Vector3.forward);
		}
		StartCoroutine("FireIsShot");
		float step = 3 * Time.deltaTime;
		transform.position = Vector3.MoveTowards (transform.position, player.transform.position, step);
	}

	void	eliminate()
	{
		if (!dyingSound.isPlaying)
			GameObject.Destroy (gameObject);
	}

	public void EnnemyDied(){
		dyingSound.Play();
		isDead = true;
		gameObject.GetComponent<SpriteRenderer>().color = Color.red;
		eliminate ();
	}

	// Update is called once per frame
	void Update () {
		if (isDead)
			eliminate();
		else if (alert) {
			trackingPlayer();
		}
	}
}
