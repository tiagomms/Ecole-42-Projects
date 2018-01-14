using UnityEngine;
using System.Collections;

public class rotateEnemyCanon : MonoBehaviour {

	private int ammoForMissile = 8;
	public GameObject	gunShot;
	public GameObject	missileShot;
	public AudioSource	gunSound;
	public AudioSource	missileSound;
	[HideInInspector]public GameObject shooter;

	void Start() {
		shooter = gameObject.transform.parent.gameObject;
	}

	public void RotateTheCanon(Vector3 playerPos, bool ifShooting)
	{
		Vector3 shootingDirection = playerPos - transform.position;
		shootingDirection.y = 0;
		transform.rotation = Quaternion.LookRotation(shootingDirection);
		if (ifShooting) {
			Vector3 direction = playerPos - transform.position;
			direction.y = 0;
			if (ammoForMissile == 0 || Random.Range (0, 5) != 0) {
				gunSound.Play ();
				GameObject.Instantiate (gunShot, transform.position, Quaternion.LookRotation(transform.forward));
				gunShot.GetComponent<shooting> ().tankTag = gameObject.tag;
				gunShot.GetComponent<shooting> ().shooter = shooter;
			} else {
				missileSound.Play ();
				GameObject.Instantiate (missileShot, transform.position, Quaternion.LookRotation(transform.forward));
				missileShot.GetComponent<shooting> ().tankTag = gameObject.tag;
				missileShot.GetComponent<shooting> ().shooter = shooter;
				ammoForMissile--;
			}
		}
	}

}
