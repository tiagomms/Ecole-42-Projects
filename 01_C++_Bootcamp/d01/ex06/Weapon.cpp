// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Weapon.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:18:51 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:19:00 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	return;
}

Weapon::~Weapon(){
	return;
}

std::string const & Weapon::getType( void ) const
{
	return this->_type;
}

void	Weapon::setType( std::string new_type )
{
	this->_type = new_type;
}