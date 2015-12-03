using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GUIStats : MonoBehaviour {

	public GameObject mainCharacter;

	private bool state = false;
	private float coolDown = 0.6f;
	private float timer = 0.6f;

	public GameObject im;

	public Text forUI;
	public Text agiUI;
	public Text conUI;

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		forUI.text = "FOR : " + mainCharacter.GetComponent<MayaScript>().FOR.ToString();
		agiUI.text = "AGI : " + mainCharacter.GetComponent<MayaScript>().AGI.ToString();
		conUI.text = "CON : " + mainCharacter.GetComponent<MayaScript>().CON.ToString();

		timer -= Time.deltaTime;
		if (Input.GetKeyDown(KeyCode.E) && timer <= 0.0f)
		{
			timer = coolDown;
			if (state) {
				StartCoroutine(transPanel(60, -60, -3));
			} else {
				StartCoroutine(transPanel(-60, 60, 3));
			}
			state = (state) ? false : true;
		}
	}

	IEnumerator transPanel(int from, int to, int way)
	{
		for (int i = from; i != to ; i += way)
		{
			im.GetComponent<RectTransform>().position = new Vector2(im.GetComponent<RectTransform>().position.x, i);
			yield return new WaitForSeconds(0.01f);
		}
	}
}
