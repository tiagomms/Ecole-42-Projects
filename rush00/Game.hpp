#ifndef GAME_HPP
# define GAME_HPP
#include <iostream>
//#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h> //usleep;
#include "AVaisseau.hpp"
#include "Enemy.hpp"
#include "PlayerShip.hpp"
#include "Missile.hpp"

#define MISSILE_MAX 50;
#define ENEMY_MAX 20;

/*
struct vaisseau{
	int x,y;
	vaisseau(int col, int row);
	vaisseau();
};
*/

class Game
{
private:
	int	_points, _delay, _maxwidth, _maxheight;
	char _direction;
	//vaisseau enemy;
	AVaisseau 	*	_enemies;
	AVaisseau		_player;

	//std::vector<vaisseau> ship;

	bool 			doCollide(AVaisseau & ship1, AVaisseau & ship2);
	bool 			insideWall(AVaisseau & ship);
	bool 			playerCollide();
	void 			movePlayer(AVaisseau & player);
	void 			shootPlayer();

	void			createMissile(AVaisseau & ship);
	Missile		&	getMissileByIndex(AVaisseau & ship, int index);
	void			deleteMissileByIndex(AVaisseau & ship, int index);

	void 			moveFleet();
	void			moveMissilesFromShip(AVaisseau & ship);
//	void 			shootFleet();
	void 			start(WINDOW *win);
	void 			CreateEnemy();
	AVaisseau	&	getEnemy(int index) const;

	void			buildEnemyTab();
	AVaisseau *		getEnemies() const;

	AVaisseau 		getEnemyByIndex(int index) const;
	void			deleteEnemyByIndex(int index);
	Game & operator=(Game const & src);
	Game(Game const & src);

	//void			updateIndex(AVaisseau *type);

	static int  _CreateEnemyDelay;
	static int	_time;
	static int	_enemyFleetSize;
	static int	_playerFleetSize;
	static const int _EnemiesMax;


public:
	Game();
	~Game();

	
};

#endif