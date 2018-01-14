using UnityEngine;
using System.Collections;

public class CubeSpawner : MonoBehaviour {
	
	public GameObject		cubeA;
	public GameObject		cubeS;
	public GameObject		cubeD;
	public float			maxSpawnTime = 1.5f;
	private float			spawnTime;
	private float			timer = 0;
	private bool[]			exist = {false, false, false};
	private float[]			posGen = {-1.20f, 0.0f, 1.20f};
	private string[]		key = {"a", "s", "d"};
	private GameObject		instantiatedCubeA;
	private GameObject		instantiatedCubeS;
	private GameObject		instantiatedCubeD;



	// Use this for initialization
	void Start () {
		spawnTime = Random.Range (0.0f, maxSpawnTime);
	}

	//random spawn Cube
	void SpawnCube() {
		if (timer >= spawnTime) {
			timer = 0;
			spawnTime = Random.Range (0.0f, maxSpawnTime);
			int cube = Random.Range(0, 3);
			Vector3 newPos = new Vector3(posGen[cube], 0, 0);
			if (!exist[cube])
			{
				exist[cube] = true;
				if (cube == 0)
				{
					instantiatedCubeA = (GameObject) Instantiate(cubeA, newPos, Quaternion.identity);
				}
				else if (cube == 1)
				{
					instantiatedCubeS = (GameObject) Instantiate(cubeS, newPos, Quaternion.identity);
				}
				else
				{
					instantiatedCubeD = (GameObject) Instantiate(cubeD, newPos, Quaternion.identity);
				}
			}
		}
	}

	//if Cube was shot
	void KillCube() {
		int i = 0;
		float precision = 4.13f;
		while (i < 3) {
			if (Input.GetKeyDown(key[i]) && exist[i])
			{
				if (i == 0)
				{
					precision += instantiatedCubeA.transform.position[1];
					GameObject.Destroy(instantiatedCubeA);
				}
				else if (i == 1)
				{
					precision += instantiatedCubeS.transform.position[1];
					GameObject.Destroy(instantiatedCubeS);
				}
				else if (i == 2)
				{
					precision += instantiatedCubeD.transform.position[1];
					GameObject.Destroy(instantiatedCubeD);
				}
				exist[i] = false;
				Debug.Log("Precision: " + precision);
			}
			i++;
		}
	}

	//if Cube is out of bounds
	void OutOfBoundsCube () {
		if (exist [0] && instantiatedCubeA.transform.position [1] <= -4.4) {
			GameObject.Destroy (instantiatedCubeA);
			exist[0] = false;
		}
		if (exist [1] && instantiatedCubeS.transform.position [1] <= -4.4) {
			GameObject.Destroy (instantiatedCubeS);
			exist[1] = false;
		}
		if (exist [2] && instantiatedCubeD.transform.position [1] <= -4.4) {
			GameObject.Destroy (instantiatedCubeD);
			exist[2] = false;
		}
	}

	// Update is called once per frame
	void Update () {
		KillCube ();
		OutOfBoundsCube ();
		SpawnCube ();

		timer += Time.deltaTime;
	}
}
