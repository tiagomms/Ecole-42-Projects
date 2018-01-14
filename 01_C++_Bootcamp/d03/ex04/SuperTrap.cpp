// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   SuperTrap.cpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 10:15:37 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 10:15:39 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperTrap.hpp"

SuperTrap::SuperTrap() 
{
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDamage(60);
	this->setRangedAttackDamage(20);
	this->setArmorDamageReduction(5);
	this->setName("SuperTrapClone");
	std::cout << "The inner workings of my SuperTrap monicidal cloned apparatus complete (i.e. Default constructor created)" << " -  My name: " << this->getName() << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string name)
{
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDamage(60);
	this->setRangedAttackDamage(20);
	this->setArmorDamageReduction(5);
	this->setName(name);
	std::cout << "The inner workings of my SuperTrap unique monicidal apparatus complete (i.e Parameter constructor created)" << " -  My name: " << this->getName() << std::endl;
	return;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap Merciless killing machine <" << this->getName() << "> commits suicide (i.e. Destructor called)" << std::endl;
	return;
}

SuperTrap::SuperTrap( SuperTrap const & src)
{
	*this = src;
	std::cout << "A FR4G-TP unit programmed to do anything from open doors to ninja-sassinate highly important Janitory officals copied (i.e. Copy constructor called)" << " -  My name: " << this->getName() << std::endl;
	return;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & src)
{
	std::cout << "A FR-Hyperion piece of metal crap that can open doors was programmed to be exactly like another FR-Hyperion piece of metal crap that can open doors (i.e Assignation operator called)" << " -  Old name: " << this->getName();
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setMaxHitPoints(src.getMaxHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setMaxEnergyPoints(src.getMaxEnergyPoints());
	this->setLevel(src.getLevel());
	this->setMeleeAttackDamage(src.getMeleeAttackDamage());
	this->setRangedAttackDamage(src.getRangedAttackDamage());
	this->setArmorDamageReduction(src.getArmorDamageReduction());
	std::cout << " ; New identity: " << this->getName() << std::endl;
	return *this;
}
