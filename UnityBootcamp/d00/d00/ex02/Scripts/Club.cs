using UnityEngine;
using System.Collections;

public class Club : MonoBehaviour {

	public	Ball			ball;

	private int				gamePoints;
	private float 			clubSpeed;
	private int				directionClub = 1;
	private bool			spacePressed = false;

	// Use this for initialization
	void Start () {
		gamePoints = -15;
		clubSpeed = 4.0f;
	}

	void setDirectionClub ()
	{
		if (ball.getBallPositionY () > 5.60f && ball.getBallPositionY () <= 7.0f)
			directionClub = -1;
		else
			directionClub = 1;
		transform.localScale = new Vector3 (10.0f, 10.0f * directionClub, 0);
	}

	void hitBall () {
		//float currentClubSpeed;
		if (Input.GetKey ("space")) {
			spacePressed = true;
			clubSpeed += 0.1f;
			transform.Translate (0, -directionClub * 0.1f, 0);
		}
		else if (spacePressed && !Input.GetKey ("space")) {
			if ((directionClub == 1 && transform.position.y < ball.getBallPositionY()) || 
			    (directionClub == -1 && transform.position.y > ball.getBallPositionY()))//wrong for the inverted club case
			{
				transform.Translate (0, directionClub * 0.2f, 0);
			}
			else
			{
				spacePressed = false;
				ball.setBallSpeed(clubSpeed);
				gamePoints += 5;
				Debug.Log ("Score: " + gamePoints);
			}
		}
		else if (!spacePressed && !Input.GetKey("space")) {
			transform.localPosition = new Vector3 (-0.25f, ball.getBallPositionY (), 0);
			setDirectionClub();
			clubSpeed = 4.0f;
		}
	}

	// Update is called once per frame
	void Update () {
		if (ball.BallIsStopped()) {
			hitBall();
		} 

	}

}
