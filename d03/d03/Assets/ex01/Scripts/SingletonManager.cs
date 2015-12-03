using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class SingletonManager : MonoBehaviour
{
	//public static DragManager	instance { get; private set;}
	private bool 				startDrag = false;
	private Vector3 			initialPos;
	private Vector3 			currentPos;
	public	towerScript 		weapon;
	private Collider2D 			image;
	private towerScript	 		clone;

//	void Awake () {
//		instance = this;
//		weapon = GetComponent<towerScript> ();
//	}




	void getCollider ()
	{
		RaycastHit2D hit = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector2.zero);
		if ((hit && hit.collider.gameObject.tag == "draggable")) {
			image = hit.collider;
			startDrag = true;
			initialPos = image.gameObject.transform.position;
		}
	}

//	public void moveImage () {

//	}


	void HitGameObject ()
	{
		if (Input.GetMouseButton (0)) {
			if (!startDrag) {
				getCollider ();
			} else {
				currentPos = Camera.main.ScreenToWorldPoint (Input.mousePosition);
				currentPos.z = 0;
				image.gameObject.transform.position = currentPos;
			}
		} else if (Input.GetMouseButtonUp (0) && startDrag) {
			Debug.Log (image.gameObject.name);

			startDrag = false;
			Debug.Log (weapon.type);
			//Debug.Log (weapon.damage);
			//Debug.Log (weapon.range);

			clone = (towerScript)Instantiate (weapon, currentPos, Quaternion.identity);
			//Debug.Log ("weapon dragged");
			image.gameObject.transform.position = initialPos;
		}
	}
//				}
//			}

	
	void Update ()
	{
		HitGameObject ();
	}

}


//	private bool startDrag = false;
//	private Vector3 initialPos;
//	private Vector3 currentPos;
//
//	public towerScript weapon;
//
//	public delegate void DragAction(GameObject imageWeapon);
//	public static event DragAction OnDragged;
//
//	void Dragging() {
//		if (Input.GetMouseButton (0)) {
//
//			if (OnDragged != null)
//				OnDragged(Input.mousePosition);
////			//beginning of a new drag
////			if (!startDrag) { 
////				initialPos = transform.position;
////				Debug.Log ("start dragging");
////			}
////			startDrag = true;
////			currentPos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
////			currentPos.z = 0;
////			transform.position = currentPos;
////			//Debug.Log (currentPos);
//		}
//	}
//
//	void OnEnable()
//	{
//		DragManager.OnDragged += Dragger;
//	}
//	
//	
//	void OnDisable()
//	{
//		DragManager.OnDragged -= Dragger;
//	}
//
//	void Dragger () {
//		if (imageWeapon.tag == "draggable") {
//			//first case - stopped dragging
//			if (Input.GetMouseButtonUp (0)) {
//				if (startDrag) {
//					startDrag = false;
//					towerScript clone = (towerScript)Instantiate (imageWeapon, currentPos, Quaternion.identity);
//					Debug.Log ("weapon dragged");
//					
//					imageWeapon.transform.position = initialPos;
//				}
//			} else {
//				if (!startDrag) { 
//					initialPos = imageWeapon.transform.position;
//					Debug.Log ("start dragging");
//				}
//				startDrag = true;
//				currentPos = Camera.main.ScreenToWorldPoint (Input.mousePosition);
//				currentPos.z = 0;
//				transform.position = currentPos;
//			}
//		}
//	}
//
//	void StopDragging() {
//		if (Input.GetMouseButtonUp (0)) {
//			if (startDrag) {
//				startDrag = false;
//				towerScript	clone = (towerScript)Instantiate (weapon, currentPos, Quaternion.identity);
//				Debug.Log ("weapon dragged");
//
//				gameObject.transform.position = initialPos;
//			}
//		}
//	}
//
//	void Update () {
//		Dragging ();
//		StopDragging ();
//	}