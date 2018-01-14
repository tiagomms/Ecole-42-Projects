using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class TankLife : MonoBehaviour {

	public 	int 	life = 100;
	public	Text	lifeText;
	public	bool	isThePlayer = false;
	private	int		updatedLife;
	private Color	originalColor;
	public	bool	notificationGiven = false;
	private bool	doItOnce = false;

	// Use this for initialization
	void Start () {
		updatedLife = life;
		if (isThePlayer)
			originalColor = lifeText.color;

	}

	IEnumerator lifeDecreased() {
		lifeText.color = Color.red;
		yield return new WaitForSeconds (3f);
		notificationGiven = false;
		lifeText.color = originalColor;
	}

	// Update is called once per frame
	void Update () {
		if (life <= 0) {
			if (isThePlayer && !doItOnce) { 
				doItOnce = true;
				Application.LoadLevel("ex00");
			}
			else
				Destroy(gameObject);
		}
		if (updatedLife != life)
			notificationGiven = true;
		else
			notificationGiven = false;
		if (isThePlayer) {
			lifeText.text = life.ToString ();
			if (notificationGiven)
				StartCoroutine ("lifeDecreased");
			updatedLife = life;
		}
	}
}
