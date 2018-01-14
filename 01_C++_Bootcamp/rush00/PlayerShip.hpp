// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PlayerShip.hpp                                        :+:      :+:
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

#ifndef PLAYERSHIP_HPP
# define PLAYERSHIP_HPP

# include "AVaisseau.hpp"
//# include "Missile.hpp"

class PlayerShip : public AVaisseau { //,public GameEntity

public:
	
	virtual 			~PlayerShip(); //Canonical	
	virtual void		fire() const;//controled
	PlayerShip(int x, int y);
	PlayerShip(); //Canonical
	PlayerShip(PlayerShip const & src); //Canonical
	PlayerShip & operator=(PlayerShip const & src); // Canonical	
	

private:
	static const std::string 	_PlayerName;
	static const int			_PlayerLives;
	static const int			_PlayerMHP;
	static const int			_PlayerTailleX;
	static const int			_PlayerTailleY;
	static const char			_PlayerBordersChar;
	static const char			_PlayerInsideChar;
	//static const Missile		_PlayerWeapon;
	static const int			_PlayerShootingDir;
	static const int			_PlayerPointsAfterDeath;
//	static int					_PlayerFleetIndex;
	static int					_PlayerVitesseX;
	static int					_PlayerVitesseY;
	static const char			_PlayerMissileChar;



}; 

#endif