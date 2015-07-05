// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   RadScorpion.cpp                                        :+:      :+:
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

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion const & src) {
	*this = src;
	return;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & src)
{
	this->_type = src.getType();
	this->_hp = src.getHP();
	return *this;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

void RadScorpion::takeDamage(int damage)
{
	return Enemy::takeDamage(damage);
}