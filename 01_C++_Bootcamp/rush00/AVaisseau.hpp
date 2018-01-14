// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   AVaisseau.hpp                                        :+:      :+:
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

#ifndef AVAISSEAU_HPP
# define AVAISSEAU_HPP

#include <iostream>
class Missile;

#define MISSILE_MAX 50;

class AVaisseau {

public:
	
	virtual 			~AVaisseau();
	AVaisseau(std::string name, int	lives, int cHP, int mHP, Missile * missile, int nbrMissiles,
		int posX, int posY, int vitesseX, int vitesseY, int tailleX, int tailleY, char bordersChar,
		char insideChar, char missileChar, int pointsAfterDeath, int shootingDir);
	AVaisseau(); //Canonical
	AVaisseau(AVaisseau const & src); //Canonical
	AVaisseau & operator=(AVaisseau const & src); // Canonical	
	//AVaisseau 			* getNext();
	//void				setNext(AVaisseau *shipPtr);
	int					getLives() const;
	int					getCHP() const;
	int					getMHP() const;	

	int					getX() const;
	int					getY() const;
	int					getVitesseX() const;
	int					getVitesseY() const;

	int					getTailleX() const;
	int					getTailleY() const;
	char				getBordersChar() const;
	char				getInsideChar() const;
	char				getMissileChar() const;
	int					getShootingDir() const;
	int					getPointsAfterDeath() const;
//	int					getIndex() const;
	std::string const &	getName() const;
	//virtual	void		fire() const = 0;
	void				takeDamage(int damage);
	void				changePosition(int x, int y);


	void				setX(int x);
	void				setY(int y);
	void				setVitesseX(int x);
	void				setVitesseY(int y);
	
	void				buildMissileTab();
	Missile *			getMissileTab() const;

	Missile &			getMissile(int index) const;
	//Missile *			getNextMissile() const;	

	int					getNbrMissiles() const;
	void				deleteMissile(int index);
	void				addMissile();
	int					getMissileMax() const;
	int					getEActivated() const;

//	void				setIndex(int index);
//	int					getFleetSize() const;
//	void				incrementFleet();
//	void				decrementFleet();

	bool				isDead();

//	AVaisseau *			getShipByIndex(int index);
//	void				deleteShipByIndex(int index);


protected:


	std::string _name; //name for character and type for enemy
	int			_lives;
	int			_cHP;
	int			_mHP;	
	Missile *	_missileTab;
	int			_nbrMissiles;
	int			_posX;
	int			_posY;
	int			_vitesseX;
	int			_vitesseY;		
	int			_tailleX;
	int			_tailleY;
	char		_bordersChar;
	char		_insideChar;
	char		_missileChar;
	int			_pointsAfterDeath;	
	int			_shootingDir;
	static const int _MissileMax;
	int			_Eactivated;
//	int			_index;
//	int			_fleetSize;



//	AVaisseau *	_next;

private:


};

#endif