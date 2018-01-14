// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Brain.cpp                                          :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:16:07 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:16:08 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "My brain is born" << std::endl;	
	return;
}

Brain::~Brain()
{
	std::cout << "My brain is dead" << std::endl;
	return;
}

//ostringstream gets whatever asked transformed into a string
//Objects of this class use a string buffer that contains a sequence of 
//characters. This sequence of characters can be accessed directly as a 
//string object, using member str.

std::string	Brain::identify( void ) const
{
	std::ostringstream address;
	std::string brainId;

	address << (void const *)this;
	brainId = address.str();
	return brainId;
}
