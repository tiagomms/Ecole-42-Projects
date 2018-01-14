using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class SkillManager : MonoBehaviour {
	
	private bool state = false;
	private float coolDown = 0.1f;
	private float timer = 0.1f;

	public GameObject panelTree;
	public GameObject mainCharacter;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		timer -= Time.deltaTime;
		if (Input.GetKeyDown(KeyCode.N) && timer <= 0.0f)
		{
			timer = coolDown;
			if (!state) {
				StartCoroutine(transPanel(0, 70, 7));
			} else {
				StartCoroutine(transPanel(0, -70, -7));
			}
			state = (state) ? false : true;
		}
		GameObject pointsUI = GameObject.Find("Points");
		pointsUI.GetComponent<Text>().text = "Points to use : " + mainCharacter.GetComponent<MayaScript>().talent;
	}

	IEnumerator transPanel(int from, int to, int way)
	{
		for (int i = from; i != to ; i += way)
		{
			panelTree.GetComponent<RectTransform>().position = new Vector2(panelTree.GetComponent<RectTransform>().position.x, panelTree.GetComponent<RectTransform>().position.y - i);
			yield return new WaitForSeconds(0.01f);
		}
	}
}
