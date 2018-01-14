// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PlayerShip.cpp                                        :+:      :+:
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

#include "PlayerShip.hpp"

const std::string	PlayerShip::_PlayerName = "MEE";
const int			PlayerShip::_PlayerLives = 5;
const int			PlayerShip::_PlayerMHP = 100;
const int			PlayerShip::_PlayerTailleX = 4;
const int			PlayerShip::_PlayerTailleY = 3;
const char			PlayerShip::_PlayerBordersChar = '@';
const char			PlayerShip::_PlayerInsideChar = 'x';
const int			PlayerShip::_PlayerShootingDir = -1;
const int			PlayerShip::_PlayerPointsAfterDeath = 0;
//int					PlayerShip::_PlayerFleetIndex = 0;
int					PlayerShip::_PlayerVitesseX = 0;
int					PlayerShip::_PlayerVitesseY = 0;
const char			PlayerShip::_PlayerMissileChar = '.';

PlayerShip::PlayerShip()
{
//	PlayerShip::_PlayerFleetIndex++;
	return;
}

PlayerShip::PlayerShip(int x, int y) :  AVaisseau(PlayerShip::_PlayerName,
										PlayerShip::_PlayerLives,
										PlayerShip::_PlayerMHP,
										PlayerShip::_PlayerMHP,
										NULL,
										0,
										x,
										y,
										PlayerShip::_PlayerVitesseX,
										PlayerShip::_PlayerVitesseY,
										PlayerShip::_PlayerTailleX,
										PlayerShip::_PlayerTailleY,
										PlayerShip::_PlayerBordersChar,
										PlayerShip::_PlayerInsideChar,
										PlayerShip::_PlayerMissileChar,
										PlayerShip::_PlayerPointsAfterDeath,
										PlayerShip::_PlayerShootingDir)
//										PlayerShip::_PlayerFleetIndex, 
//										PlayerShip::_PlayerFleetIndex + 1)
{
//	PlayerShip::_PlayerFleetIndex++;
	return;
}

PlayerShip::~PlayerShip()
{
//	std::cout << "PlayerShip Dead - GAME OVER\n";
//	PlayerShip::_PlayerFleetIndex--;
	return;
}

PlayerShip::PlayerShip(PlayerShip const & src)
{
	*this = src;
	return;
} //Canonical

PlayerShip & PlayerShip::operator=(PlayerShip const & src)
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
} // Canonical

void		PlayerShip::fire() const
{
	std::cout << "player shootingDir: " << this->getShootingDir() << "*x" << std::endl;
}
