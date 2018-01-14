// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Missile.hpp                                        :+:      :+:
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

#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "AVaisseau.hpp"

class Missile : public AVaisseau
{

public:
	virtual 			~Missile(); //Canonical
	virtual void		fire() const;//automatic
	Missile(int posX, int posY, char missileShape, int shootingDir);
	Missile(); //Canonical
	void		setActivated(int activated);
	int			getActivated() const;
	Missile & operator=(Missile const & src); // Canonical	
	Missile(Missile const & src); //Canonical	
//	virtual Missile *			getMissile() const;
//	virtual Missile *			getNextMissile() const;	
//	virtual void				setMissile(Missile * missile);
		

protected:


private:
	static const std::string 	_MissileName;
	static const int			_MissileLives;
	static const int			_MissileMHP;
	static const int			_MissileTailleX;
	static const int			_MissileTailleY;
	static const int			_MissilePointsAfterDeath;
//	static int					_MissileFleetIndex;
	static const int			_MissileVitesseX;
	static const int			_MissileVitesseY;
	int							_activated;

};

#endif
