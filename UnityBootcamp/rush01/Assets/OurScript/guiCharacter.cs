using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class guiCharacter : MonoBehaviour {

	public GameObject	mainCharacter;
	public GameObject	healthUI;
	public GameObject	xpUI;
	public Text			levelUI;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		// get health and xp from mainCharacter ==> modify values to gui
		int life = mainCharacter.GetComponent<MayaScript>().life;
		int lifeMax = mainCharacter.GetComponent<MayaScript>().lifeMax;
		int xp = mainCharacter.GetComponent<MayaScript>().xp;
		int xpToNextLevel = mainCharacter.GetComponent<MayaScript>().xpToNextLevel;
		int level = mainCharacter.GetComponent<MayaScript>().level;

		healthUI.GetComponent<UIBarScript>().UpdateValue(life, lifeMax);
		xpUI.GetComponent<UIBarScript>().UpdateValue(xp, xpToNextLevel);
		levelUI.text = "Level : " + level.ToString();
	}
}
