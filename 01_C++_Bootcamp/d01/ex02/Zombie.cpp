// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Zombie.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 14:35:20 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 14:35:53 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie::Zombie() : _name("Default") {
	return;
}

Zombie::Zombie(std::string name) : _name(name) {
	return;
}

Zombie::~Zombie() {
	std::cout << this->_name << " was destroyed.\n";
	return;
}

void	Zombie::announce( void ) const
{
	std::cout  << "<" << this->_name << " (" << this->_type 
		<< ")> Braiiiiiiinnnssss...\n";
}
