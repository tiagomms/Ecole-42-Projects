// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Missile.cpp                                        :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 15:51:29 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 15:51:34 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Missile.hpp"

const std::string 	Missile::_MissileName = "Missile";
const int			Missile::_MissileLives = 1;
const int			Missile::_MissileMHP = 1;
const int			Missile::_MissileTailleX = 1;
const int			Missile::_MissileTailleY = 1;
const int			Missile::_MissilePointsAfterDeath = 0;
//int					Missile::_MissileFleetIndex = 0;
const int			Missile::_MissileVitesseX = 0;
const int			Missile::_MissileVitesseY = 2;

Missile::Missile() : _activated(0) {}

Missile::Missile(Missile const & src) {
	*this = src;
	return;
}

Missile & Missile::operator=(Missile const & src)
{
	this->_name = src.getName();
	this->_lives = src.getLives();
	this->_cHP = src.getCHP();
	this->_mHP = src.getMHP();
	this->_missileTab = NULL;
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
	this->_activated = src.getActivated();
//	this->_index = 0;
//	this->_fleetSize = 1;	
//	this->_next = NULL;
	return *this;
}

Missile::Missile(int posX, int posY, char missileShape, int shootingDir) :
				AVaisseau(Missile::_MissileName,
						Missile::_MissileLives,
						Missile::_MissileMHP,
						Missile::_MissileMHP,
						NULL,
						0,
						posX,
						posY,
						Missile::_MissileVitesseX,
						Missile::_MissileVitesseY * shootingDir,
						Missile::_MissileTailleX,
						Missile::_MissileTailleY,
						missileShape,
						missileShape,
						missileShape,
						Missile::_MissilePointsAfterDeath,
						shootingDir)
						//Missile::_MissileFleetIndex,
						//Missile::_MissileFleetIndex + 1)									
{
	this->_activated = 1;
	this->_missileTab = NULL;
//	Missile::_MissileFleetIndex++;
	return;
}

Missile::~Missile()
{
//	Missile::_MissileFleetIndex--;
	return;
}

int			Missile::getActivated() const
{
	return this->_activated;
}

void Missile::fire() const
{
	std::cout << "BAM BAM BAM\n";
}

/*
Missile *	Missile::getMissile() const
{
	return this->_missile;
}

Missile *	Missile::getNextMissile() const
{
	if (this->_next)
		return this->_next;
	else
		return NULL;
}

void		Missile::setMissile(Missile * missile)
{
	this->_missile = missile;
}
*/