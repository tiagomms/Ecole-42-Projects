// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Victim.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:06:07 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:13 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"

Victim::Victim()
{
	return;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << this->getName() 
	<< " just popped !" << std::endl;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->getName() 
	<< " just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	return;
}

Victim & Victim::operator=(Victim const & src)
{
	this->_name = src.getName();
	return *this;
}

std::string Victim::getName() const
{
	return this->_name;
}

void		Victim::getPolymorphed() const
{
	std::cout << this->getName() 
	<< " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &	operator<<( std::ostream & o, Victim const &victim)
{
	o << "I'm " << victim.getName() << " and I like otters !" << std::endl;
	return (o);
}