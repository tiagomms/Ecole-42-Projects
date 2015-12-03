using UnityEngine;
using System.Collections;

public class testCam : MonoBehaviour {
	public Player player;
	[HideInInspector]public		AudioSource		youLost;
	public						AudioClip		youLostClip;
	[HideInInspector]public		AudioSource		dyingPlayerSound;
	public						AudioClip		dyingPlayerClip;
	private						bool			playSong1 = false;
	private						bool			playSong2 = false;

	
	// Use this for initialization
	void Start () {
		youLost = gameObject.AddComponent<AudioSource>();
		youLost.clip = youLostClip;
		dyingPlayerSound = gameObject.AddComponent<AudioSource>();
		dyingPlayerSound.clip = dyingPlayerClip;
	}

	IEnumerator playDyingSong() {
		if (!playSong1) {
			dyingPlayerSound.Play ();
			playSong1 = true;
		}
		yield return new WaitForSeconds (3.0f);
		Camera.main.orthographicSize = 1f;
		if (!playSong2) {
			youLost.Play ();
			playSong2 = true;
		}
		yield return new WaitForSeconds (3.0f);
		Application.LoadLevel("Endgame");
		player.GetComponent<Player> ().isPlayerDead = false;
	}

	// Update is called once per frame
	void Update () {
		transform.localPosition = new Vector3 (player.transform.localPosition.x, player.transform.localPosition.y, -10);
		if (player.GetComponent<Player> ().isPlayerDead) {
			StartCoroutine("playDyingSong");
		}
	}
}
