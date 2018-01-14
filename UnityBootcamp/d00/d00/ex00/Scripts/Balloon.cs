using UnityEngine;
using System.Collections;

public class Balloon : MonoBehaviour {
	
	public float        scaleLimit = 5.0f;
	public float		scaleMin = 0.1f;
	public int			maxBreaths = 20;
	private float		currentScale;
	private float		timer = 0;
	private int			nbrBreaths;
	private bool		game = true;
	private bool        exploded = false;
	private bool		printed = false;
	
	
	// Use this for initialization
	void Start () {
		nbrBreaths = maxBreaths;
		currentScale = 2.0f;
	}
	
	void blow () {
		if (Input.GetKeyDown ("space") && nbrBreaths >= 4) {
			currentScale += 0.5f;
			nbrBreaths -= 4;
		} 
		else {
			currentScale -= 0.1f;
			nbrBreaths += 1;
		}
		transform.localScale = new Vector3 (currentScale, currentScale, 0);
	}
	
	void ifExploded () {
		if (currentScale >= scaleLimit) {
			exploded = true;
			game = false;
		}
	}
	
	void ifDeflated () {
		if (currentScale <= scaleMin) {
			game = false;
		}
	}
	
	void printDeadLog () {
		if (!printed) {
			int endTime = Mathf.RoundToInt (timer);
			Debug.Log (string.Format ("Balloon life time: {0}s", endTime));
			printed = true;
		}
	}
	
	// Update is called once per frame
	void Update () {
		
		//if game is still on and balloon has not yet exploded
		if (game && !exploded) {
			
			//check if Space was pressed
			blow ();
			
			//check if balloon Exploded
			ifExploded();
			
			//check if balloon Deflated
			ifDeflated();
			
			//check Breath
			if (nbrBreaths > maxBreaths)
				nbrBreaths = maxBreaths;
			
			timer += Time.deltaTime;
		} 
		else {
			// if game is over --> check if balloon exploded or not
			if (exploded)
			{
				currentScale -= 0.2f;
				transform.localScale = new Vector3 (currentScale, currentScale, 0);
				if (currentScale <= scaleMin)
				{
					printDeadLog();
					GameObject.Destroy(gameObject);
				}
			}
			else
			{
				printDeadLog();
				transform.localScale = new Vector3 (0.05f, 0.05f, 0);
			}
		}
	}
}
