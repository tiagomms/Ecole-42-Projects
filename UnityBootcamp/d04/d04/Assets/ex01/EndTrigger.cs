using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class EndTrigger : MonoBehaviour {

	private	Animator	animator;
	private float		timer = 0.0f;
	private float		timerMax = 6.0f;
	private bool		triggerSong = false;
	private bool		gotScore = false;
	public Text			finalScore;
	public Sonic		sonic;
	public timerScript	timerS;

	public AudioSource aEnd;
	public AudioSource levelMusic;

	private int pointsFromTimer;

	public delegate void triggerEndEvent();
	public triggerEndEvent endGame;

	public string nameOfLevel;
	public string scoreSave;

	private	int fscore = 0;

	// Use this for initialization
	void Start () {
		animator = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		if (triggerSong)
			timer += Time.deltaTime;
		if (timer >= timerMax)
		{
			aEnd.Stop();
			finalScore.text = "SCORE : " + fscore.ToString();
			if (timer >= timerMax + 3.0f)
			{	
					Application.LoadLevel("DataSelect");
			}
		}
	}

	void OnTriggerEnter2D(Collider2D collision) {
		if (collision.gameObject.tag == "Player" && !triggerSong)
		{
			pointsFromTimer = (timerS.timeElapsed > 200f ? 0 : 100 * (int)timerS.timeElapsed);
			fscore = sonic.rings * 100 + (20000 - pointsFromTimer);

			if (PlayerPrefs.GetInt(scoreSave) < fscore)
				PlayerPrefs.SetInt(scoreSave, fscore);
			PlayerPrefs.SetInt("coinsGet", PlayerPrefs.GetInt("coinsGet") + sonic.rings);
			PlayerPrefs.SetInt(nameOfLevel, 1);
			PlayerPrefs.Save ();

			triggerSong = true;
			animator.SetTrigger("sign");
			animator.SetBool("end", true);
			
			//play end music
			levelMusic.Stop();
			aEnd.Play();
			if (endGame != null)
				endGame();
		}
	}
}
