using UnityEngine;
using System.Collections;

public class FireBallShot : MonoBehaviour {

	private float 	speed = 10f;
	public	int		damage = 0;
	private bool	wasTriggeredBefore = false;

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.tag == "Enemy") {
			other.gameObject.GetComponent<EnemyScript>().life -= damage;
			if (!wasTriggeredBefore) {
				Destroy(gameObject, 2f);
				//startExplosion?
				wasTriggeredBefore = true;
			}
		}

	}


	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		transform.position += gameObject.transform.forward * speed * Time.deltaTime;
	}
}
