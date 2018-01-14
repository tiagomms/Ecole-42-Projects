using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour {

	private float 	movementFriction = 0.05f;
	private float 	wallFriction = 0.5f;
	
	private float 	ballSpeed = 0.0f;
	private int		directionBall = 1;
	private float 	ballPositionY = -5.0f;
	private bool	ballExist = true;
	// Use this for initialization
	void Start () {
	}

	void getPosition () {
		float previousBallSpeed = ballSpeed;
		float newPositionY;
		if (previousBallSpeed != 0.0f) {
			transform.Translate (0, previousBallSpeed * Time.deltaTime * directionBall, 0);
			newPositionY = transform.position[1];

			ballPositionY = Mathf.Clamp (newPositionY, -7.0f, 7.0f);
			if (ballPositionY != newPositionY)
			{
				directionBall *= -1;
				ballSpeed -= wallFriction;
			}
			else 
				ballSpeed -= movementFriction;
			if (ballSpeed < 0.0f)
				ballSpeed = 0.0f;
		}
	}

	public bool getBallExist()
	{
		return ballExist;
	}

	public float getBallPositionY ()
	{
		return ballPositionY;
	}

	public float getBallSpeed ()
	{
		return ballSpeed;
	}

	public bool BallIsStopped ()
	{
		return ballSpeed == 0f && ballExist;
	}

	public void setBallSpeed (float clubSpeed)
	{
		ballSpeed = clubSpeed;
	}

	void isBallInHole ()
	{
		if (ballSpeed < 2.0f) {
			if (ballPositionY >= 4.40f && ballPositionY <= 5.60f) {
				GameObject.Destroy (gameObject);
				ballExist = false;
			}
		}
	}

	// Update is called once per frame
	void Update () {
		if (getBallExist () && ballSpeed != 0.0f) {
			getPosition();
			isBallInHole();
		}
		else if (BallIsStopped() ) {
			if (Mathf.Clamp (ballPositionY, -7.0f, 4.40f) == 4.40f)
				directionBall = -1;
			else
				directionBall = 1;
		}
		
	}
}
