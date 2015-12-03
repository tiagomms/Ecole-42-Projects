using UnityEngine;
using UnityEngine.UI;

using System.Collections;
using System.Collections.Generic;

public class manageLevels : MonoBehaviour {

	public List<GameObject>	levels = new List<GameObject>();
	public GameObject		lockedSprite;
	public GameObject		selectBox;

	private int				index;
	private GameObject		currentLevel;

	// PREF PLAYERS
	private int				scoreLevel;
	private int 			isLocked;
	private string			levelName;
	private int				numberOfLifesLost;
	private int				numberOfRings;

	public AudioSource		movingSong;

	public Text				levelNameText;
	public Text				scoreLevelText;
	public Text				numberOfLifesLostText;
	public Text				numberOfRingsText;

	// Use this for initialization
	void Start () {
		// IS LOCKED
		index = 0;
		foreach (GameObject level in levels)
		{
			int isL = PlayerPrefs.GetInt(level.name);
			if (isL == 0) {
				GameObject.Instantiate(lockedSprite, level.transform.position, Quaternion.identity);
			}
		}
		numberOfLifesLost = PlayerPrefs.GetInt ("lifesLost");		
		numberOfRings = PlayerPrefs.GetInt ("coinsGet");


	}

	
	// Update is called once per frame
	void Update () {
		currentLevel = levels[index];

		levelName = PlayerPrefs.GetString(currentLevel.name + "_name");
		Debug.Log(levelName);
		scoreLevel = PlayerPrefs.GetInt (("score" + currentLevel.name.Substring(5, 3)));
		isLocked = PlayerPrefs.GetInt(currentLevel.name);

		selectBox.transform.position = currentLevel.transform.position;

		// Print current information about stage


		// manage directions
		if (Input.GetKeyDown("left")){
			movingSong.Play();
			index = (index != 0) ? index - 1 : 8;
		}
		if (Input.GetKeyDown("right")){
			movingSong.Play();
			index = (index != 8) ? index + 1 : 0;
		}
		if (Input.GetKeyDown("up")){
			movingSong.Play();
			index = (index > 2) ? index - 3 : index + 6;
		}
		if (Input.GetKeyDown("down")){
			movingSong.Play();
			index = (index < 6) ? index + 3 : index - 6;
		}

		if (Input.GetKeyDown("return"))
		{
			if (isLocked == 1)
			{
				Application.LoadLevel(currentLevel.name);
			}
		}

		numberOfLifesLostText.text = numberOfLifesLost.ToString();
		numberOfRingsText.text = numberOfRings.ToString();
		levelNameText.text = levelName;
		scoreLevelText.text = "Best Score : " + scoreLevel + " pts";
	}
}
