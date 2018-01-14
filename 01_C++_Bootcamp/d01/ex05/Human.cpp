// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Human.cpp                                          :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:16:56 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:16:57 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human()
{
	std::cout << "Human is born" << std::endl;	
	return;
}

Human::~Human()
{
	std::cout << "Human dead" << std::endl;
	return;
}

std::string Human::identify ( void ) const
{
	return this->_myBrain.identify();
}

//return the object reference so it can go to the Brain class.
//const in the beginning because the private attribute in Human is const.
Brain const	& Human::getBrain( void ) const
{
	return this->_myBrain;
}
