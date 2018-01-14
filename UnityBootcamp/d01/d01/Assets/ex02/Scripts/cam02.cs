using UnityEngine;
using System.Collections;

public class cam02 : MonoBehaviour {

	public 	GameObject 	Claire;
	public 	GameObject	Thomas;
	public 	GameObject	John;
	private	GameObject	current;
	private Vector3		ClaireResetPos;
	private Vector3		ThomasResetPos;
	private Vector3		JohnResetPos;
	private bool		claireGameWon = false;
	private bool		thomasGameWon = false;
	private bool		johnGameWon = false;
	private bool		gameWon = false;
//	private Camera		mainCamera;

	// Use this for initialization
	void Start () {
		Claire.tag = "Player";
		Thomas.tag = "Untagged";
		John.tag = "Untagged";
		ClaireResetPos = Claire.transform.position;
		ThomasResetPos = Thomas.transform.position;
		JohnResetPos = John.transform.position;
		Debug.Log ("Press: o - overview camera; 1, 2, 3 to select player; r - restart");
	}

	void isGameWon()
	{
		if (!gameWon) {
			//Debug.Log ("Position: " + Claire.transform.localPosition);
			if ((Claire.transform.localPosition.y >= -13.3f && Claire.transform.localPosition.y <= -13.0f) &&
			    (Claire.transform.localPosition.x >= 50f && Claire.transform.localPosition.x <= 58f) && !claireGameWon) {
				claireGameWon = true;
				Debug.Log ("Claire has reached her destination! Continue");
			}
			if ((Thomas.transform.localPosition.y >= -4.65f && Thomas.transform.localPosition.y <= -4.55f) &&
			    (Thomas.transform.localPosition.x >= 50f && Thomas.transform.localPosition.x <= 55f) && !thomasGameWon) {
				thomasGameWon = true;
				Debug.Log ("Thomas has reached his destination! Continue");
			}
			if ((John.transform.localPosition.y >= 8.3f && John.transform.localPosition.y <= 8.4f) &&
			    (John.transform.localPosition.x >= 35.5f && John.transform.localPosition.x <= 40.5f) && !johnGameWon) {
				johnGameWon = true;
				Debug.Log ("John has reached his destination! Continue");
			}
			if (claireGameWon && thomasGameWon && johnGameWon)
			{
				gameWon = true;
				Debug.Log ("You won!");
			}
		}
	}

	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown("1"))
		{
			Claire.tag = "Player";
			Thomas.tag = "Untagged";
			John.tag = "Untagged";
		}
		else if (Input.GetKeyDown("2"))
		{
			Claire.tag = "Untagged";
			Thomas.tag = "Player";
			John.tag = "Untagged";
		}
		else if (Input.GetKeyDown("3"))
		{
			Claire.tag = "Untagged";
			Thomas.tag = "Untagged";
			John.tag = "Player";
		}
		else if (Input.GetKeyDown("r"))
		{
			Claire.tag = "Player";
			Thomas.tag = "Untagged";
			John.tag = "Untagged";
			Claire.transform.position = ClaireResetPos;
			Thomas.transform.position = ThomasResetPos;
			John.transform.position = JohnResetPos;
			claireGameWon = false;
			thomasGameWon = false;
			johnGameWon = false;
			gameWon = false;
			Debug.Log ("Game restarted");
		}
		else if (Input.GetKeyDown("o"))
		{
			Claire.tag = "Untagged";
			Thomas.tag = "Untagged";
			John.tag = "Untagged";
			Debug.Log ("Press 1,2 or 3 to continue game");
		}
		current = GameObject.FindWithTag ("Player");
		if (current != null) {
			transform.position = new Vector3 (current.transform.position [0], current.transform.position [1] + 10, -10);
			Camera.main.orthographicSize = 20;
		}
		else
		{
			transform.position = new Vector3(61, 28, -10);
			Camera.main.orthographicSize = 110;
		}
		isGameWon ();
	}
}
