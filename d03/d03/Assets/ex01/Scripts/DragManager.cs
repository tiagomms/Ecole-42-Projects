using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class DragManager : MonoBehaviour
{
	private static bool 		startDrag = false;
	private Vector3 			initialPos;
	private Vector3 			currentPos;

	public  gameManager			gm;
	private	towerScript			weapon;

	public	towerScript			CAN;
	public	towerScript			GAT;
	public	towerScript			ROK;

	private Collider2D 			image;

	public void getCollider ()
	{
		RaycastHit2D hit = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector2.zero);
		if ((hit && hit.collider.gameObject.tag == "draggable")) {
			image = hit.collider;

			if (hit.collider.gameObject.GetComponent<Image>().color == Color.white)
			{
				startDrag = true;
				initialPos = image.gameObject.transform.position;
			}
		}
	}

	bool putTower() {
		RaycastHit2D hit = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector2.zero);
		if (hit) {
			if (hit.collider.gameObject.tag == "tower" || hit.collider.gameObject.tag == "draggable") {
				return false;
			}
			return true;
		}
		return false;
	}

	void HitGameObject ()
	{
		if (Input.GetMouseButton (0)) {
			if (!startDrag) {
				getCollider ();
			} else {
				currentPos = Camera.main.ScreenToWorldPoint (Input.mousePosition);
				currentPos.z = 0;
				if (image != null)
					image.gameObject.transform.position = currentPos;
			}
		} else if (Input.GetMouseButtonUp (0) && startDrag) {
			startDrag = false;
			image.gameObject.transform.position = initialPos;
			//do raycast here to determine if it is good to drop here something
			if (putTower()) {
				if (image.gameObject.name == "canon_sign")
				{
					GameObject.Instantiate (CAN, currentPos, Quaternion.identity);
					gm.playerEnergy -= CAN.energy;
				}
				else if (image.gameObject.name == "gatling_sign") {
					GameObject.Instantiate (GAT, currentPos, Quaternion.identity);
					gm.playerEnergy -= GAT.energy;
				}
				else if (image.gameObject.name == "rocket_sign") {
					GameObject.Instantiate (ROK, currentPos, Quaternion.identity);
					gm.playerEnergy -= ROK.energy;
				}
			}
			image = null;
		}
	}

	
	void Update ()
	{
		HitGameObject ();
	}

}