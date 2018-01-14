using UnityEngine;
using System.Collections;

public class initPlayerPrefScript : MonoBehaviour
{

	// Use this for initialization
	void Start ()
	{
	
	}
	
	// Update is called once per frame
	void Update ()
	{
		// INIT PLAYER PREF \\
		if (!PlayerPrefs.HasKey ("init")) {
			PlayerPrefs.SetString ("init", "done");
			PlayerPrefs.SetInt ("lifesLost", 0);		
			PlayerPrefs.SetInt ("coinsGet", 0);				

			//Score on each level
			PlayerPrefs.SetInt ("score1_1", 0);
			PlayerPrefs.SetInt ("score1_2", 0);
			PlayerPrefs.SetInt ("score1_3", 0);
			PlayerPrefs.SetInt ("score2_1", 0);
			PlayerPrefs.SetInt ("score2_2", 0);
			PlayerPrefs.SetInt ("score2_3", 0);
			PlayerPrefs.SetInt ("score3_1", 0);
			PlayerPrefs.SetInt ("score3_2", 0);
			PlayerPrefs.SetInt ("score3_3", 0);
						
			//if level is locked or unlocked : 0 = locked | 1 : unlocked
			PlayerPrefs.SetInt ("level1_1", 1);
			PlayerPrefs.SetInt ("level1_2", 0);
			PlayerPrefs.SetInt ("level1_3", 0);
			PlayerPrefs.SetInt ("level2_1", 1);
			PlayerPrefs.SetInt ("level2_2", 0);
			PlayerPrefs.SetInt ("level2_3", 0);
			PlayerPrefs.SetInt ("level3_1", 1);
			PlayerPrefs.SetInt ("level3_2", 0);
			PlayerPrefs.SetInt ("level3_3", 0);

			PlayerPrefs.SetString("level1_1_name", "Old Ruin 1");
			PlayerPrefs.SetString("level1_2_name", "Old Ruin 2");
			PlayerPrefs.SetString("level1_3_name", "Old Ruin 3");

			PlayerPrefs.SetString("level2_1_name", "Sand City 1");
			PlayerPrefs.SetString("level2_2_name", "Sand City 2");
			PlayerPrefs.SetString("level2_3_name", "Sand City 3");

			PlayerPrefs.SetString("level3_1_name", "Space Station 1");
			PlayerPrefs.SetString("level3_2_name", "Space Station 2");
			PlayerPrefs.SetString("level3_3_name", "Space Station 3");
		}
	}
}
