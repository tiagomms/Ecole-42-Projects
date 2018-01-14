using UnityEngine.UI;
using System.Collections;
using UnityEngine;

public class timerScript : MonoBehaviour {

	public float	timeElapsed = 0.0f;
	private int		minute = 0;
	private int		seconds = 0;

	public Text		timerLabel;

	private string	outPut = "";
	public EndTrigger endTrigger;

	private bool	stop = false;

	// Use this for initialization
	void Start () {
	
	}

	void OnEnable()
	{
		endTrigger.endGame += stopTimer;
	}

	void OnDisable()
	{
		endTrigger.endGame += stopTimer;
	}

	void stopTimer()
	{
		stop = true;
	}

	// Update is called once per frame
	void Update () {
		if (!stop)
		{
			timeElapsed += Time.deltaTime;
			minute = (int)(timeElapsed / 60);
			seconds = (int)(timeElapsed % 60);
			if (seconds < 10)
				outPut = "Time " + minute.ToString() + " : 0" + seconds.ToString();
			else
				outPut = "Time " + minute.ToString() + " : " + seconds.ToString();
			timerLabel.text = outPut;
		}
	}
}
