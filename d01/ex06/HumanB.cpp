// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   HumanB.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:18:08 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:18:08 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	return;
}

HumanB::~HumanB(){
	return;
}

//don't forget object reference!
void HumanB::setWeapon(Weapon &club) {
	this->_weapon = &club;
}

void HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his " 
	<< this->_weapon->getType() << std::endl;
}
