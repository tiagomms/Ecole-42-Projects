using UnityEngine;
using System.Collections;

public class weaponOnFloor : MonoBehaviour {
	
	public	GameObject	weaponPicked;
	public	GameObject	player;
	[HideInInspector]public	int	nbrOfBullets = 0;
	[HideInInspector]public	bool		usedWeapon = false;
	private bool		spawned = false;
	private	Vector3		playerDirection;
	[HideInInspector]public		float	speedThrown = 0.0f;


	public 	AudioClip				pickUpWeaponClip;
	[HideInInspector]public	AudioSource				pickUpWeaponSound;


	void Start() {
		player = GameObject.FindWithTag ("Player");
		Vector2 aux = player.GetComponent<Player> ().moveDirection.normalized;
		playerDirection = new Vector3(aux.x, aux.y, 0f);
		pickUpWeaponSound = gameObject.AddComponent<AudioSource>();
		pickUpWeaponSound.clip = pickUpWeaponClip;
	}

	public void WeaponThrown()
	{
		speedThrown = 6.0f;
	}

	// Use this for initialization
	void OnTriggerStay2D(Collider2D other) {
		if (other.gameObject.tag == "Player") {
			if ((Input.GetMouseButtonDown (0) || Input.GetKeyDown ("e"))  && !player.GetComponent<Player>().hasWeapon) { // && !isWeaponSpawned
				if (spawned)
					return;
				spawned = true;
				player.GetComponent<Player>().GotWeapon();
				GameObject clone = (GameObject)Instantiate (weaponPicked, other.gameObject.transform.position, Quaternion.identity);

				clone.GetComponent<Weapon>().noBullets = usedWeapon;
				int nbr = nbrOfBullets;
				if (nbr == 0 && !usedWeapon)
					nbr = clone.GetComponent<Weapon>().maxAmmountBullets;
				clone.GetComponent<Weapon>().setAvailableBullets(nbr);

				Destroy (gameObject);

			}
		}
	}

	void Update () {
		if (speedThrown > 0.0f) {
			transform.position = Vector3.MoveTowards(transform.position, transform.position + playerDirection, speedThrown * Time.deltaTime );
			transform.rotation = Quaternion.AngleAxis( transform.rotation.z + speedThrown * 10, Vector3.forward);
			speedThrown -= 1f;
		}
	}

}
