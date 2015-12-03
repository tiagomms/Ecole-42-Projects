using UnityEngine;
using System.Collections;


public class EnemyAI : MonoBehaviour
{
	public float patrolSpeed = 6f;                          // The nav mesh agent's speed when patrolling.
	public float chaseSpeed = 9f;                           // The nav mesh agent's speed when chasing.
	public float chaseWaitTime = 5f;                        // The amount of time to wait when the last sighting is reached.
	public float patrolWaitTime = 1f;                       // The amount of time to wait when the patrol way point is reached.
	public Transform[] patrolWayPoints;                     // An array of transforms for the patrol route.

	private EnemySight enemySight;                          // Reference to the EnemySight script.
	private NavMeshAgent nav;                               // Reference to the nav mesh agent.
	public	Transform player;                               // Reference to the player's transform.
	private TankLife playerHealth;                      // Reference to the PlayerHealth script.
	private TankLife enemyHealth;
	private LastPlayerSighting lastPlayerSighting;          // Reference to the last global sighting of the player. --> connect to player is Spotted
	private float chaseTimer;                               // A timer for the chaseWaitTime.
	private float patrolTimer;                              // A timer for the patrolWaitTime.
	private int wayPointIndex;                              // A counter for the way point array.
	public	rotateEnemyCanon	canonDirection;
	
	private bool		reload = false;
	public	float		reloadTime;

	IEnumerator Reload() {
		reload = true;
		yield return new WaitForSeconds (reloadTime);
		reload = false; 
	}

	void Awake ()
	{
		// Setting up the references.
		enemySight = GetComponent<EnemySight>();
		nav = GetComponent<NavMeshAgent>();
		player = player.transform;
		playerHealth = player.GetComponent<TankLife>();
		lastPlayerSighting = GetComponent<LastPlayerSighting> ();
		enemyHealth = GetComponent<TankLife> ();
		//canonDirection = GetComponent<rotateEnemyCanon> ();
		//lastPlayerSighting = GameObject.FindGameObjectWithTag(Tags.gameController).GetComponent<LastPlayerSighting>(); //?
	}
	
	
	void Update ()
	{
		// If the player is in sight and is alive...
		if (enemySight.playerInSight && playerHealth.life > 0f && !reload) {
			Shooting ();
		}
		// If the player has been sighted and isn't dead...
		else if(enemySight.personalLastSighting != lastPlayerSighting.resetPosition && playerHealth.life > 0f)
			// ... chase.
			Chasing();
		
		// Otherwise...
		else
			// ... patrol.
			Patrolling();
	}
	
	
	void Shooting ()
	{
		// Stop the enemy where it is.
		nav.Stop();

		canonDirection.RotateTheCanon (player.transform.position, true);
		StartCoroutine("Reload");

	}
	
	
	void Chasing ()
	{
		// Create a vector from the enemy to the last sighting of the player.

		Vector3 sightingDeltaPos = enemySight.personalLastSighting - transform.position;
		canonDirection.RotateTheCanon (enemySight.personalLastSighting, false);
		// If the the last personal sighting of the player is not close...
		if(sightingDeltaPos.sqrMagnitude > 4f)
			// ... set the destination for the NavMeshAgent to the last personal sighting of the player.
			nav.destination = enemySight.personalLastSighting;
		
		// Set the appropriate speed for the NavMeshAgent.
		nav.speed = chaseSpeed;
		
		// If near the last personal sighting...
		if(nav.remainingDistance < nav.stoppingDistance)
		{
			// ... increment the timer.
			chaseTimer += Time.deltaTime;
			
			// If the timer exceeds the wait time...
			if(chaseTimer >= chaseWaitTime)
			{
				// ... reset last global sighting, the last personal sighting and the timer.
				lastPlayerSighting.position = lastPlayerSighting.resetPosition;
				enemySight.personalLastSighting = lastPlayerSighting.resetPosition;
				chaseTimer = 0f;
			}
		}
		else
			// If not near the last sighting personal sighting of the player, reset the timer.
			chaseTimer = 0f;
	}
	
	
	void Patrolling ()
	{
		// Set an appropriate speed for the NavMeshAgent.
		nav.speed = patrolSpeed;

		// If near the next waypoint or there is no destination...
		if(nav.destination == lastPlayerSighting.resetPosition || nav.remainingDistance < nav.stoppingDistance)
		{
			// ... increment the timer.
			patrolTimer += Time.deltaTime;
			
			// If the timer exceeds the wait time...
			if(patrolTimer >= patrolWaitTime)
			{
				// ... increment the wayPointIndex.
				if(wayPointIndex == patrolWayPoints.Length - 1)
					wayPointIndex = 0;
				else
					wayPointIndex++;
				
				// Reset the timer.
				patrolTimer = 0;
			}
		}
		else
			// If not near a destination, reset the timer.
			patrolTimer = 0;
		
		// Set the destination to the patrolWayPoint.
		nav.destination = patrolWayPoints[wayPointIndex].position;
	}
}
