using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class getDataFromGameManager : MonoBehaviour {

	public gameManager 	gm;
	public Text 		HPValue;
	public Text 		EnergyValue;

	//from prefabs. 0 , 1 , 2 based on their power level
	public towerScript			CAN;
	public towerScript			GAT;
	public towerScript			ROK;

	public GameObject			canon_sign;
	public GameObject			gatling_sign;
	public GameObject			rocket_sign;

	public Text 		canon_damage;
	public Text 		canon_range;
	public Text 		canon_energy;
	public Text 		canon_time;

	public Text 		gatling_damage;
	public Text 		gatling_range;
	public Text 		gatling_energy;
	public Text 		gatling_time;

	public Text 		rocket_damage;
	public Text 		rocket_range;
	public Text 		rocket_energy;
	public Text 		rocket_time;



	void deActivateWeapon () {
		if (CAN.energy > gm.playerEnergy) {
			canon_sign.GetComponent<Image>().color = Color.red;
		}
		else
			canon_sign.GetComponent<Image>().color = Color.white;
		
		if (ROK.energy > gm.playerEnergy) {
			rocket_sign.GetComponent<Image>().color = Color.red;
		}
		else
			rocket_sign.GetComponent<Image>().color = Color.white;
		
		if (GAT.energy > gm.playerEnergy) {
			gatling_sign.GetComponent<Image>().color = Color.red;
		}
		else
			gatling_sign.GetComponent<Image>().color = Color.white;
	}



	void updateText() {
		getHPValue ();
		getEnergyValue ();
		
		canon_damage.text = CAN.damage.ToString();
		canon_range.text = CAN.range.ToString();
		canon_energy.text = CAN.energy.ToString();
		canon_time.text = CAN.fireRate.ToString();
		
		gatling_damage.text = GAT.damage.ToString();
		gatling_range.text = GAT.range.ToString();
		gatling_energy.text = GAT.energy.ToString();
		gatling_time.text = GAT.fireRate.ToString();
		
		rocket_damage.text = ROK.damage.ToString();
		rocket_range.text = ROK.range.ToString();
		rocket_energy.text = ROK.energy.ToString();
		rocket_time.text = ROK.fireRate.ToString();
	}

	public void getHPValue () {
		HPValue.text = gm.playerHp.ToString ();
	}

	public void getEnergyValue () {
		EnergyValue.text = gm.playerEnergy.ToString ();
	}






	void Update () {
		deActivateWeapon ();
		updateText ();
	}

}
