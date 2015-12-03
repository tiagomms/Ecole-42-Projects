using UnityEngine;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class tryIt : MonoBehaviour, IPointerClickHandler {

	private bool state = false;
	public int levelRequired = 1;
	private int upgrade = 0;
	public float baseCoolDown = 0.5f;
	public float actCoolDown;
	public GameObject mainCharacter;

	public GameObject spell;

	private	float		_timer = 0.0f;

	void Update()
	{
		//when Selected in Spells Available it will be already ready
		_timer += Time.deltaTime;

		actCoolDown = (upgrade >= 1) ? baseCoolDown / upgrade : baseCoolDown;

		// will need to update the upgrade text
		if (mainCharacter.GetComponent<MayaScript>().talent <= 0 || mainCharacter.GetComponent<MayaScript>().level < levelRequired)
		{
			GetComponent<Image>().color = new Color(1f, 1f, 1f, 0.5f);
			state = false;
		}
		else
		{
			GetComponent<Image>().color = new Color(1f, 1f, 1f, 1f);
			state = true;
		}

		Text[] texts = GetComponentsInChildren<Text>();
		foreach (Text t in texts)
		{
			if (t.name == "upgrade")
			{
				t.text = upgrade.ToString() + "/5"; 
			}
			if (t.name == "available" && mainCharacter.GetComponent<MayaScript>().spellsBought.Contains(this.gameObject))
			{
				t.color = Color.yellow;
				t.text = "o";
				if (mainCharacter.GetComponent<MayaScript>().spellsAvailable.Contains(this.gameObject)) {
					t.text = (mainCharacter.GetComponent<MayaScript>().spellsAvailable.IndexOf(this.gameObject) + 1).ToString();
					t.color = Color.green;
				}
			}
			else if (t.name == "available" && !mainCharacter.GetComponent<MayaScript>().spellsBought.Contains(this.gameObject))
			{
				t.text = "";
			}
		}

		// REMOVE ALL ICONS
		foreach (GameObject g in mainCharacter.GetComponent<MayaScript>().spellsBought)
		{
			Image[] icons = g.GetComponentsInChildren<Image>();
			foreach(Image icon in icons)
			{
				if (icon.name == "icon")
				{
					icon.GetComponent<RectTransform>().position = new Vector2(-1000, -1000);
					icon.GetComponent<Image>().enabled = true;
				}
			}
		}

		// PLACE THE GOOD ONES
		int i = 0;
		foreach (GameObject g in mainCharacter.GetComponent<MayaScript>().spellsAvailable)
		{
			Image[] icons = g.GetComponentsInChildren<Image>();
			foreach(Image icon in icons)
			{
				if (icon.name == "icon")
				{
					icon.GetComponent<RectTransform>().position = new Vector2(66 + (i * 50) + i * 6, 51);
					icon.GetComponent<Image>().enabled = true;
					i += 1;

					//see if spell is ready for shooting
					if (_timer < actCoolDown)
						icon.GetComponent<Image>().color = Color.red;
					else
						icon.GetComponent<Image>().color = Color.white;
				}
			}
		}
	}

	public void OnPointerClick(PointerEventData eventData)
	{
		if (eventData.button == PointerEventData.InputButton.Left && state && upgrade < 5)
		{
			Debug.Log("Left click");
			upgrade += 1;
			mainCharacter.GetComponent<MayaScript>().talent -= 1;
			mainCharacter.GetComponent<MayaScript>().spellsBought.Add(this.gameObject);
		}
		if (eventData.button == PointerEventData.InputButton.Right && mainCharacter.GetComponent<MayaScript>().spellsBought.Contains(this.gameObject) && !mainCharacter.GetComponent<MayaScript>().spellsAvailable.Contains(this.gameObject))
		{

			mainCharacter.GetComponent<MayaScript>().spellsAvailable.Insert(mainCharacter.GetComponent<MayaScript>().indexSpell, this.gameObject);
			mainCharacter.GetComponent<MayaScript>().indexSpell += 1;
			if (mainCharacter.GetComponent<MayaScript>().indexSpell >= 4)
				mainCharacter.GetComponent<MayaScript>().indexSpell = 0;
			mainCharacter.GetComponent<MayaScript>().cleanList();
		}
	}

	public void shoot()
	{
		//check in FireworkScript (or whatever script --> like SpellsAvailableManager

		if (_timer >= actCoolDown) {
			Transform mayaTransform = mainCharacter.GetComponent<MayaScript> ().transform;
			GameObject.Instantiate (spell, mayaTransform.position, Quaternion.LookRotation (mayaTransform.forward));
			_timer = 0.0f;
		}

		// do stuff when key pressed
	}
}