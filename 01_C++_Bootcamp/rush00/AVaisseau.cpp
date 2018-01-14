// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   AVaisseau.cpp                                        :+:      :+:
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

#include "AVaisseau.hpp"
#include "Missile.hpp"

const int AVaisseau::_MissileMax = 50;

AVaisseau::AVaisseau() : _Eactivated(0)
{
	return;
}

AVaisseau::~AVaisseau()
{
	//std::cout << "Vaisseau destroyed\n";
	//delete [] this->_missileTab;
	//this->_missileTab = NULL;
	return;
}

AVaisseau::AVaisseau(AVaisseau const & src)
{
	*this = src;
	return;
} //Canonical

AVaisseau & AVaisseau::operator=(AVaisseau const & src)
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
	this->_Eactivated = src.getEActivated();
//	this->_index = 0;
//	this->_fleetSize = 1;
//	this->_next = NULL;
	return *this;	
} // Canonical

AVaisseau::AVaisseau(std::string name, int lives, int cHP, int mHP, Missile * missile, int nbrMissiles,
		int posX, int posY, int vitesseX, int vitesseY, int tailleX, int tailleY, char bordersChar,
		char insideChar, char missileChar, int pointsAfterDeath, int shootingDir) :
							_name(name),
							_lives(lives),
							_cHP(cHP),
							_mHP(mHP),
							_missileTab(missile),
							_nbrMissiles(nbrMissiles),
							_posX(posX),
							_posY(posY),
							_vitesseX(vitesseX), 
							_vitesseY(vitesseY),
							_tailleX(tailleX),
							_tailleY(tailleY),
							_bordersChar(bordersChar),
							_insideChar(insideChar),
							_missileChar(missileChar),
							_pointsAfterDeath(pointsAfterDeath),
							_shootingDir(shootingDir)
//							_index(index))
//							_fleetSize(fleetSize + 1)
{
	this->_Eactivated = 1;
	this->buildMissileTab();	
//	std::cout << "Vaisseau created\n";
	return;
}	

void				AVaisseau::takeDamage(int damage)
{
	this->_cHP -= damage;
	if (this->getCHP() <= 0 && this->getLives() > 0)
	{
		this->_lives -= 1;
		this->_cHP = this->getMHP();
	}
}

void		AVaisseau::changePosition(int x, int y)
{	
	this->setX(x);
	this->setY(y);
}

bool		AVaisseau::isDead()
{
	return this->getLives() <= 0;
}


/*
AVaisseau	*	AVaisseau::getNext()
{
	return this->_next;
}

void			AVaisseau::setNext(AVaisseau *shipPtr)
{
	this->_next = shipPtr;
}
*/

int		AVaisseau::getEActivated() const
{
	return this->_Eactivated;
}

int			AVaisseau::getCHP() const
{
	return this->_cHP;
}

int			AVaisseau::getMHP() const
{
	return this->_mHP;
}

int			AVaisseau::getX() const
{
	return this->_posX;
}

int			AVaisseau::getY() const
{
	return this->_posY;
}

int			AVaisseau::getTailleX() const
{
	return this->_tailleX;
}

int			AVaisseau::getTailleY() const
{
	return this->_tailleY;
}

char		AVaisseau::getBordersChar() const
{
	return this->_bordersChar;
}

char		AVaisseau::getInsideChar() const
{
	return this->_insideChar;
}

char		AVaisseau::getMissileChar() const
{
	return this->_missileChar;
}

int			AVaisseau::getShootingDir() const
{
	return this->_shootingDir;
}

std::string const &	AVaisseau::getName() const
{
	return this->_name;
}

int			AVaisseau::getLives() const
{
	return this->_lives;
}

int			AVaisseau::getPointsAfterDeath() const
{
	return this->_pointsAfterDeath;
}

int			AVaisseau::getVitesseX() const
{
	return this->_vitesseX;
}

int			AVaisseau::getVitesseY() const
{
	return this->_vitesseY;
}

void		AVaisseau::setVitesseX(int x)
{
	this->_vitesseX = x;
}

void		AVaisseau::setVitesseY(int y)
{
	this->_vitesseY = y;
}


void		AVaisseau::setX(int x)
{
	this->_posX = x;
}

void		AVaisseau::setY(int y)
{
	this->_posY = y;
}

/*
void		AVaisseau::setIndex(int index)
{
	this->_index = index;
}

int			AVaisseau::getIndex() const
{
	return this->_index;
}


int			AVaisseau::getFleetSize() const
{
	return this->_fleetSize;
}

void		AVaisseau::incrementFleet()
{
	this->_fleetSize++;
}

void		AVaisseau::decrementFleet()
{
	this->_fleetSize--;
}
*/

void		AVaisseau::buildMissileTab()
{
	int i;

	this->_missileTab = new Missile[AVaisseau::_MissileMax];
	i = AVaisseau::_MissileMax - 1;
	while (i)
	{
		this->_missileTab[i] = Missile();
		i--;
	}
}

Missile *	AVaisseau::getMissileTab() const
{
	return this->_missileTab;
}

Missile	&	AVaisseau::getMissile(int index) const
{
	return  (this->_missileTab)[index];
}

int			AVaisseau::getNbrMissiles() const
{
	return this->_nbrMissiles;
}

int		AVaisseau::getMissileMax() const
{
	return AVaisseau::_MissileMax;
}

void		AVaisseau::deleteMissile(int index)
{
	(this->_missileTab)[index] = Missile();
	this->_nbrMissiles--;
}

void		AVaisseau::addMissile()
{
	int i;

	i = 0;
	if (this->getNbrMissiles() >= AVaisseau::_MissileMax)
		return;
	while (i < AVaisseau::_MissileMax)
	{
		if ((this->getMissile(i)).getActivated() == 0)
		{
			(this->_missileTab)[i] = Missile(this->getX(), 
									this->getY() + this->getShootingDir(), 
									this->getMissileChar(), 
									this->getShootingDir());
			this->_nbrMissiles++;
			return;
		}
		i++;
	}
}


/*

Missile *	AVaisseau::getMissile() const
{
	return this->_missile;
}



void		AVaisseau::setMissile(Missile * missile)
{
	this->_missile = missile;
}
*/