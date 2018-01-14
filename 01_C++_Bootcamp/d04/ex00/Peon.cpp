// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Peon.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:44 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"

Peon::Peon() {
	return;
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const & src)
{
	*this = src;
	return;
}

Peon & Peon::operator=(Peon const & src)
{
	this->_name = src.getName();
	return *this;
}

void		Peon::getPolymorphed() const
{
	std::cout << this->getName() 
	<< " has been turned into a pink pony !" << std::endl;
}