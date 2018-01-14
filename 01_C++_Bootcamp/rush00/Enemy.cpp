// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Enemy.cpp                                        :+:      :+:
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

#include "Enemy.hpp"

const std::string 	Enemy::_EnemyName = "Enemy";
const int			Enemy::_EnemyLives = 1;
const int			Enemy::_EnemyMHP = 20;
const int			Enemy::_EnemyTailleX = 2;
const int			Enemy::_EnemyTailleY = 2;
const char			Enemy::_EnemyBordersChar = '*';
const char			Enemy::_EnemyInsideChar = ':';
const int			Enemy::_EnemyShootingDir = 1;
const int			Enemy::_EnemyPointsAfterDeath = 10;
int					Enemy::_EnemyVitesseX = 0;
int					Enemy::_EnemyVitesseY = 1;
const char			Enemy::_EnemyMissileChar = '.';
//const int			Enemy::_CreateEnemyDelay = 100000;

Enemy::Enemy()
{
	return;
}

Enemy::Enemy(int x, int y) :  AVaisseau(Enemy::_EnemyName,
										Enemy::_EnemyLives,
										Enemy::_EnemyMHP,
										Enemy::_EnemyMHP,
										NULL,
										0,
										x,
										y,
										Enemy::_EnemyVitesseX,
										Enemy::_EnemyVitesseY,
										Enemy::_EnemyTailleX,
										Enemy::_EnemyTailleY,
										Enemy::_EnemyBordersChar,
										Enemy::_EnemyInsideChar,
										Enemy::_EnemyMissileChar,
										Enemy::_EnemyPointsAfterDeath,
										Enemy::_EnemyShootingDir)
//										Enemy::_EnemyFleetIndex,
//										Enemy::_EnemyFleetIndex + 1)
{
//	Enemy::_EnemyFleetIndex++;
	return;
}

Enemy::~Enemy()
{
//	std::cout << "Enemy Dead - Yay\n";
//	Enemy::_EnemyFleetIndex--;
	return;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return;
}

Enemy & Enemy::operator=(Enemy const & src)
{
	this->_name = src.getName();
	this->_lives = src.getLives();
	this->_cHP = src.getCHP();
	this->_mHP = src.getMHP();
	this->_missileTab = src.getMissileTab();
	this->_nbrMissiles = src.getNbrMissiles();
	this->_posX = src.getX();
	this->_posY = src.getY();
	this->_vitesseX = src.getVitesseX();
	this->_vitesseY = src.getVitesseY();	
	this->_tailleX = src.getTailleX();
	this->_tailleY = src.getTailleY();
	this->_bordersChar = src.getBordersChar();
	this->_insideChar = src.getInsideChar();
	this->_missileChar = src.getMissileChar();
	this->_pointsAfterDeath = src.getPointsAfterDeath();
	this->_shootingDir = src.getShootingDir();
	return *this;	
}

void		Enemy::fire() const
{
	std::cout << "Enemy shootingDir: " << this->getShootingDir() << "*x" << std::endl;
}
