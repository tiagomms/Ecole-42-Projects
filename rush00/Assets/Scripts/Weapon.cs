using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine.UI;

public class Weapon : MonoBehaviour {

	public	float 					fireRate;
	public	float					range;
	public 	GameObject				image;

	public 	GameObject 				ammo;

	[HideInInspector]public	AudioSource				discardWeaponSound;
	public	string					soundName;
	[HideInInspector]public AudioSource				shotSound;
	[HideInInspector]public	AudioSource				blank;

	public 	AudioClip				discardWeaponClip;
	public 	AudioClip				shotClip;
	public	AudioClip				blankClip;
	[HideInInspector]public Vector3	targetPos;
	
	public	bool					isWhiteWeapon;
	[HideInInspector]public  bool	noBullets = false;

	private	int						availableBullets;
	public	int						maxAmmountBullets;
	private	bool					canShoot = true;

	public	string					shooterTag;

	public enum 					Type{uzi, shotgun, sniper, saber};
	public 							Type type;

	public Text						WeaponName;
	public Text						maxBulletsText;
	public Text						availableBulletsText;


	public void ActivateWeaponSounds() {
		discardWeaponSound = gameObject.AddComponent<AudioSource>();
		discardWeaponSound.clip = discardWeaponClip;
		
		shotSound = gameObject.AddComponent<AudioSource>();
		shotSound.clip = shotClip;
		
		blank = gameObject.AddComponent<AudioSource>();
		blank.clip = blankClip;
	}

	void Start () {

	}

	//IMPORTANT - WHEN Weapon assigned to enemy, it is important to get tag name


	IEnumerator RangeIsOver(GameObject bullet) {
		canShoot = true;
		yield return new WaitForSeconds(range);
		Destroy(bullet);
	}

	public	void	setAvailableBullets(int nbr)
	{
		availableBullets = nbr;
	}

	public void discardWeapon() {
		discardWeaponSound.Play (); 
		GameObject clone = (GameObject)Instantiate (image, transform.position, Quaternion.identity);
		clone.GetComponent<weaponOnFloor> ().WeaponThrown ();
		clone.GetComponent<weaponOnFloor> ().nbrOfBullets = availableBullets;
		clone.GetComponent<weaponOnFloor> ().usedWeapon = noBullets;
		Destroy (gameObject);
	}

	public void shotFire () {
		if ((availableBullets > 0 || shooterTag == "Ennemy") && canShoot) {
			if (shooterTag != "Ennemy" && !isWhiteWeapon)
				availableBullets--;
			GameObject bullet = (GameObject)Instantiate (ammo.gameObject, transform.position, transform.rotation);
			canShoot = false;
			bullet.GetComponent<AmmoScript> ().targetPos = targetPos;

			if (!isWhiteWeapon){
				bullet.GetComponent<AmmoScript> ().gotShotDirection ();
			}
			if (isWhiteWeapon) {
				bullet.transform.parent = gameObject.transform;
				Debug.Log(bullet);
//				bullet.GetComponent<AmmoScript> ().gotStab();
			}
//			Debug.Log ("timer: " + bullet.GetComponent<AmmoScript> ().timer);
			shotSound.Play();
			bullet.GetComponent<AmmoScript> ().weaponOwner = shooterTag;
			bullet.GetComponent<AmmoScript> ().isShot = true;
			bullet.transform.localScale = new Vector2 (1, 1);
			StartCoroutine ("RangeIsOver", bullet);
		} 

		else if (availableBullets == 0) {
			blank.Play ();
			noBullets = true;
		}
	}

	void Update () {

	}

}