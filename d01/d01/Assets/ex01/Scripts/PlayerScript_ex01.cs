using UnityEngine;
using System.Collections;

public class PlayerScript_ex01 : MonoBehaviour
{
	
	private	Rigidbody2D		rb;
	private Vector2			forceX;
	private Vector2			forceY;
	public 	bool			canJump = false;
	private float			previousPositionY;
	private bool			gameWon = false;

	// Use this for initialization
	void Start ()
	{
		rb = GetComponent<Rigidbody2D> ();
		forceY = new Vector2 (0f, 550.0f);
		forceX = new Vector2 (50.0f, 0.0f);
		previousPositionY = gameObject.transform.position.y;
	}

	void isSamePositionY ()
	{
		canJump = (gameObject.transform.position.y == previousPositionY);
	}

	void isGameWon()
	{
		if (!gameWon) {
			if ((gameObject.transform.position.y >= 22.38f && gameObject.transform.position.y <= 22.45f) &&
				(gameObject.transform.position.x >= 45.40f && gameObject.transform.position.x <= 47.70f)) {
				gameWon = true;
				Debug.Log ("You won!");
			}
		}
	}
	
	// Update is called once per frame
	void Update ()
	{
		isSamePositionY ();
		if (gameObject.tag == "Player") {
			if (Input.GetKey ("left")) {
				rb.AddForce (-forceX, ForceMode2D.Force);
			}
			if (Input.GetKey ("right")) {
				rb.AddForce (forceX, ForceMode2D.Force);
			}
			if (Input.GetKeyDown ("space") && canJump) {
				rb.AddForce (forceY, ForceMode2D.Force);
			}
		}
		previousPositionY = gameObject.transform.position.y;
		isGameWon();
	}
}
