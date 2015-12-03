using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PlayerScript : MonoBehaviour {

	public 	Slider		discretionSlider;
	[HideInInspector]public 	float		discretionLevel = 0.0f;
	public 	bool		inTheShadows = true;
	private	bool		doItOnce = false;
	private	float		DetentionSpeed = 5.0f;
	private	float		OffTheHookSpeed = 1.5f;
	private float		timerOffShadows = 0.0f;
	private float		timerInShadows = 0.0f;
	[HideInInspector]public bool		imDead = false;

	public	Rigidbody 	rb;
	public	float		playerVelocity;
	public	Text		percentage;
	
	public	AudioSource	alertSound;
	public	AudioSource	NormalSound;
	public	AudioSource Alarm;
	public	AudioSource Restart;
	public	AudioSource Walking;

	[HideInInspector]public bool			GotKeyChain = false;

	public	Camera		PlayerCamera;
	public	Camera		MegaphoneCamera;
	
	public	Text		GuideText;
	[HideInInspector]public	bool		deletedInitialText = false;



	// Use this for initialization
	void Start () {
		//discretionSlider = GetComponent<Slider> ();
		rb = gameObject.GetComponent<Rigidbody> ();
		NormalSound.playOnAwake = true;
		alertSound.playOnAwake = false;
		Alarm.playOnAwake = false;
		Restart.playOnAwake = false;

		PlayerCamera.enabled = true;
		MegaphoneCamera.enabled = false;
		MegaphoneCamera.GetComponent<AudioListener>().enabled = false;
		PlayerCamera.GetComponent<AudioListener>().enabled = true;
	}

	IEnumerator deleteGuideText() {
		yield return new WaitForSeconds (8.0f);
		deletedInitialText = true;
		GuideText.text = "";
	}

	IEnumerator YouLose() {
		if (doItOnce) {
			doItOnce = false;
			alertSound.Stop ();
			Alarm.Play();
			PlayerCamera.enabled = false;
			PlayerCamera.GetComponent<AudioListener>().enabled = false;
			MegaphoneCamera.enabled = true;
			MegaphoneCamera.GetComponent<AudioListener>().enabled = true;
			imDead = true;
		}
		GuideText.text = "Game Over. Restarting Simulation";
		yield return new WaitForSeconds (8.0f);
		if (!Restart.isPlaying)
			Restart.Play ();
		yield return new WaitForSeconds (4.4f);
		Application.LoadLevel ("ex02");
	}

	// Update is called once per frame
	void Update () {
		if (!imDead) {
			if (!deletedInitialText)
				StartCoroutine("deleteGuideText");
			if (discretionLevel >= 75.0f) {
				percentage.color = Color.red;
				if (!doItOnce) {
					doItOnce = true;
					timerOffShadows /= 20f;
					NormalSound.Stop ();
				}
				if (!alertSound.isPlaying)
					alertSound.Play ();
			} else {
				if (doItOnce)
					alertSound.Stop ();
				if (!NormalSound.isPlaying) {
					NormalSound.Play ();
				}
				percentage.color = Color.white;
				doItOnce = false;
			}
			//playerVelocity = Vector3.Magnitude (rb.velocity) * 1000f;
			if (playerVelocity > 0.5f) {
				if (!Walking.isPlaying)
					Walking.Play();
			}
			if (!inTheShadows || playerVelocity > 5.0f) {
				timerInShadows = 0.0f;
				if (playerVelocity > 5f)
					timerOffShadows += playerVelocity * Time.deltaTime / 120f;
				else
					timerOffShadows += Time.deltaTime / 60f;
				discretionLevel += DetentionSpeed * timerOffShadows;
			} else {
				timerOffShadows = 0.0f;
				timerInShadows += Time.deltaTime / 60f;
				discretionLevel -= OffTheHookSpeed * timerInShadows;
			}
			discretionLevel = Mathf.Clamp (discretionLevel, 0f, 100f);
			if (discretionLevel < 10f)
				percentage.text = "0" + Mathf.RoundToInt (discretionLevel).ToString () + " %";
			else
				percentage.text = Mathf.RoundToInt (discretionLevel).ToString () + " %";
			discretionSlider.value = Mathf.RoundToInt (discretionLevel);
		}
		if (discretionLevel >= 99.9f) {
			StartCoroutine("YouLose");
		}
	}
}
