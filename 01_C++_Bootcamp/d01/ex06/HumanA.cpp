// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   HumanA.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:17:50 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:17:51 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & weapon) : _name(name), _weapon(weapon) 
{
	return;
}

HumanA::~HumanA(){
	return;
}

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " 
	<< this->_weapon.getType() << std::endl;
}
