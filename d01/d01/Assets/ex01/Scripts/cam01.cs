using UnityEngine;
using System.Collections;

public class cam01 : MonoBehaviour {

	public 	GameObject 	Claire;
	public 	GameObject	Thomas;
	public 	GameObject	John;
	private	GameObject	current;
	private Vector3		ClaireResetPos;
	private Vector3		ThomasResetPos;
	private Vector3		JohnResetPos;

	// Use this for initialization
	void Start () {
		Claire.tag = "Player";
		Thomas.tag = "Untagged";
		John.tag = "Untagged";
		ClaireResetPos = Claire.transform.position;
		ThomasResetPos = Thomas.transform.position;
		JohnResetPos = John.transform.position;
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown("1"))
		{
			Claire.tag = "Player";
			Thomas.tag = "Untagged";
			John.tag = "Untagged";
		}
		else if (Input.GetKeyDown("2"))
		{
			Claire.tag = "Untagged";
			Thomas.tag = "Player";
			John.tag = "Untagged";
		}
		else if (Input.GetKeyDown("3"))
		{
			Claire.tag = "Untagged";
			Thomas.tag = "Untagged";
			John.tag = "Player";
		}
		else if (Input.GetKeyDown("r"))
		{
			Claire.tag = "Player";
			Thomas.tag = "Untagged";
			John.tag = "Untagged";
			Claire.transform.position = ClaireResetPos;
			Thomas.transform.position = ThomasResetPos;
			John.transform.position = JohnResetPos;
		}
		current = GameObject.FindWithTag ("Player");
		transform.position = new Vector3(current.transform.position[0], current.transform.position[1] + 10, -10);
	}
}
