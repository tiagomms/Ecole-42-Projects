using UnityEngine;
using System.Collections;

public class shooting : MonoBehaviour {

	public 	int				damage;
	[HideInInspector]public	ParticleSystem	bullet;
	private RaycastHit		hit;
	public	GameObject		explosion;
	public	string			tankTag;
	private float			extraSpeed = 10f;
	[HideInInspector] public GameObject shooter;



	// Use this for initialization
	void Start () {
		bullet = GetComponent<ParticleSystem> ();

	}

	IEnumerator destroyBullet() {
		yield return new WaitForSeconds (bullet.duration);
		GameObject.Instantiate (explosion, transform.position, Quaternion.identity);
		Destroy (gameObject);
	}
	
	// Update is called once per frame
	void Update () {
		StartCoroutine ("destroyBullet");
		//Debug.DrawRay (transform.position, gameObject.transform.forward, Color.red, bullet.duration);
		if (Physics.SphereCast (gameObject.transform.position, bullet.startSize * 0.8f, gameObject.transform.forward, 
		                     out hit, bullet.startSpeed * Time.deltaTime * extraSpeed)) {
			if (hit.collider.gameObject != shooter) {
				if ((hit.collider.name == "Player" || hit.collider.name == "Enemy 1" || hit.collider.name == "Enemy 2" || hit.collider.name == "Enemy 3") && !hit.collider.isTrigger) {
					hit.collider.gameObject.transform.GetComponent<TankLife> ().life -= damage;
					GameObject.Instantiate (explosion, transform.position, Quaternion.identity);
					Destroy (gameObject);
				}

			}
		}
		gameObject.transform.position += gameObject.transform.forward * bullet.startSpeed * Time.deltaTime * extraSpeed;
	}
}
