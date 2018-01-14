// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   AWeapon.cpp                                        :+:      :+:
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

#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(AWeapon const & src) {
	*this = src;
	return;
}

AWeapon & AWeapon::operator=(AWeapon const & src)
{
	this->_name = src.getName();
	this->_apcost = src.getAPCost();
	this->_damage = src.getDamage();
	return *this;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
	_name(name), _apcost(apcost), _damage(damage)
{
	return;
}

int		AWeapon::getDamage() const
{
	return this->_damage;
}

int		AWeapon::getAPCost() const
{
	return this->_apcost;
}

std::string AWeapon::getName() const
{
	return this->_name;
}

AWeapon::~AWeapon()
{
	return;
}