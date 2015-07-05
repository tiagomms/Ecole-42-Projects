// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PowerFist.cpp                                        :+:      :+:
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

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist(PowerFist const & src) {
	*this = src;
	return;
}

PowerFist & PowerFist::operator=(PowerFist const & src)
{
	this->_name = src.getName();
	this->_apcost = src.getAPCost();
	this->_damage = src.getDamage();
	return *this;
}

PowerFist::~PowerFist()
{
	return;
}

void PowerFist::attack() const
{
	std::cout <<  "* pschhh... SBAM! *" << std::endl;
}