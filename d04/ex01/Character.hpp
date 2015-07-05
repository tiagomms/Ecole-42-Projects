// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Character.hpp                                        :+:      :+:
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

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <iostream>

class Character
{

private:
	Character(); //Canonical
	std::string _name;
	int 		_ap;
	AWeapon *	_weapon;

protected:

public:
	Character(std::string const & name);
	~Character(); //Canonical
	Character(Character const & src); //Canonical
	Character & operator=(Character const & src); // Canonical
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	int					getAP() const;
	std::string virtual getName() const;
	AWeapon *			getWeapon() const;

};

std::ostream &	operator<<( std::ostream & o, Character const &dude);

#endif