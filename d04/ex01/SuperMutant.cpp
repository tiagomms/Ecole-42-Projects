// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   SuperMutant.cpp                                        :+:      :+:
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

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "SuperMutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const & src) {
	*this = src;
	return;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & src)
{
	this->_type = src.getType();
	this->_hp = src.getHP();
	return *this;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}

void SuperMutant::takeDamage(int damage)
{
	return Enemy::takeDamage(damage - 3);
}