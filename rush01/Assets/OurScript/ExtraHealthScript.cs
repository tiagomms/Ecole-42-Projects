using UnityEngine;
using System.Collections;

public class ExtraHealthScript : MonoBehaviour {

	//addparticles here

	void OnTriggerEnter(Collider other)
	{
		if (other.gameObject.tag == "Player") {
			other.gameObject.GetComponent<MayaScript>().life += Mathf.RoundToInt(0.2f * other.gameObject.GetComponent<MayaScript>().lifeMax);
			Destroy(gameObject);
		}
	}
	
}
