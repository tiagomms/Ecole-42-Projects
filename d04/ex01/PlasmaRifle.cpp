// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PlasmaRifle.cpp                                        :+:      :+:
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

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) {
	*this = src;
	return;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & src)
{
	this->_name = src.getName();
	this->_apcost = src.getAPCost();
	this->_damage = src.getDamage();
	return *this;
}

PlasmaRifle::~PlasmaRifle()
{
	return;
}

void PlasmaRifle::attack() const
{
	std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}