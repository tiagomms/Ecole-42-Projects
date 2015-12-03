using UnityEngine;
using System.Collections;

public class ifPlayerInSight : MonoBehaviour {

	public GameObject[]	Enemies;
	public GameObject	player;                               // Reference to the player's transform.


	bool	spotPlayer() {
		foreach (GameObject enemy in Enemies) {
			if (enemy) {
				if (enemy.GetComponent<EnemySight>().playerInSight) {
					return true;
				}
			}
		}
		return false;
	}

	// Update is called once per frame
	void Update () {
		player.GetComponent<moveTank>().wasPlayerSpotted = spotPlayer();
	}
}
