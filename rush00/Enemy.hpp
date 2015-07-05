// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Enemy.hpp                                        :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 15:51:20 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 15:51:34 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AVaisseau.hpp"
//# include "Missile.hpp"

class Enemy : public AVaisseau { //,public GameEntity

public:
	virtual 			~Enemy(); //Canonical
	Enemy(); //Canonical
	virtual void		fire() const;//automatic
	Enemy(int x, int y);
	Enemy(Enemy const & src); //Canonical
	Enemy & operator=(Enemy const & src); // Canonical

		

protected:


private:
	static const std::string 	_EnemyName;
	static const int			_EnemyLives;
	static const int			_EnemyMHP;
	static const int			_EnemyTailleX;
	static const int			_EnemyTailleY;
	static const char			_EnemyBordersChar;
	static const char			_EnemyInsideChar;
	//static const Missile		_EnemyWeapon;
	static const int			_EnemyShootingDir;
	static const int			_EnemyPointsAfterDeath;
//	static int					_EnemyFleetIndex;
	static int					_EnemyVitesseX;
	static int					_EnemyVitesseY;
	static const char			_EnemyMissileChar;
	//	static const int			_CreateEnemyDelay;
//	int							_delay;


}; 

#endif