// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:17 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer() {
	return;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->getName() << ", " << this->getTitle() 
	<< ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->getName() << ", " << this->getTitle() 
	<< ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	return;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & src)
{
	this->_name = src.getName();
	this->_title = src.getTitle();
	return *this;
}

std::string Sorcerer::getName() const
{
	return this->_name;
}

std::string Sorcerer::getTitle() const
{
	return this->_title;
}

void Sorcerer::polymorph(Victim const & victim)
{
	victim.getPolymorphed();
}

std::ostream &	operator<<( std::ostream & o, Sorcerer const &wizard)
{
	o << "I am " << wizard.getName() << ", " << wizard.getTitle()
	<< ", and I like ponies !" << std::endl;
	return (o);
}