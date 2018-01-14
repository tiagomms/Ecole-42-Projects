// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Character.cpp                                        :+:      :+:
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

#include "Character.hpp"

Character::Character() {}

Character::Character(Character const & src) {
	*this = src;
	return;
}

Character & Character::operator=(Character const & src)
{
	this->_name = src.getName();
	this->_ap = src.getAP();
	this->_weapon = src.getWeapon();
	return *this;
}

Character::Character(std::string const & name) :
	_name(name), _ap(40), _weapon(NULL)
{
	return;
}

void Character::recoverAP()
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void Character::equip(AWeapon* new_weapon)
{
	this->_weapon = new_weapon;
}

void Character::attack(Enemy *enemy)
{
	std::cout << this->getName() << " attacks " << enemy->getType() << " with a "
	<< this->_weapon->getName() << std::endl;
	if (this->_weapon && this->_ap >= this->_weapon->getAPCost())
	{
		this->_weapon->attack();
		this->_ap -= this->_weapon->getAPCost();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}

}

std::string Character::getName() const
{
	return this->_name;
}

int Character::getAP() const
{
	return this->_ap;
}

AWeapon * Character::getWeapon() const
{
	return this->_weapon;
}

Character::~Character()
{
	return;
}

std::ostream &	operator<<( std::ostream & o, Character const &dude)
{
	o << dude.getName() << " has " << dude.getAP() << " AP and ";

	if (dude.getWeapon())
		o << "wields a " << (dude.getWeapon())->getName();
	else
		o << "is unarmed";
	
	o << std::endl;
	return (o);
}