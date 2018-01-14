using UnityEngine;
using System.Collections;

public class MayaFunctions : MonoBehaviour {
	
	private MayaScript maya;
	public AudioSource hurt;
	public AudioSource hurtZombie;

	void Awake() {
		maya = GetComponent<MayaScript> ();
	}

	void	MayaAgility() {
		maya.extraTimer = 10 / maya.AGI;
		maya._agent.speed = 3 + maya.AGI / 5;
	}

	// Use this for initialization
	public void updateAfterLevelUp () {

		maya.level += 1;
		maya.lifeMax += 15;
		maya.life = maya.lifeMax;
		maya.xp -= maya.xpToNextLevel;
		maya.xpToNextLevel += 10;
		maya.talent += 1;
		
		// INCREASE STATS
		maya.FOR += 2;
		maya.AGI += 1;
		maya.CON += 2;

		MayaAgility ();
	}

	public void	MayaAttack(GameObject enemy) {

		if (enemy.GetComponent<EnemyScript> ().life > 0) {
			enemy.GetComponent<EnemyScript> ().life -= maya.FOR;
			if (!hurtZombie.isPlaying)
				hurtZombie.Play();
		}else {
			maya.xp += enemy.GetComponent<EnemyScript> ().lifeMax;
		}
	}

	public void	EnemyAttack(int enemyDamage) {
		if (!hurt.isPlaying)
			hurt.Play();
		if (enemyDamage - maya.CON > 0) 
			maya.life -= (enemyDamage - maya.CON / 2);
		if (maya.life <= 0)
			maya.life = 0;
	}

}
