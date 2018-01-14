// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:
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

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :	_name("ClapTrap Default")
{
	std::cout << "ClapTrap Default complete (i.e. Default constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

ClapTrap::ClapTrap( unsigned int hitPoints,
		unsigned int	maxHitPoints,
		unsigned int 	energyPoints,	
		unsigned int 	maxEnergyPoints,
		unsigned int	level,	
		unsigned int	meleeAttackDamage,	
		unsigned int	rangedAttackDamage,
		unsigned int	armorDamageReduction, 
		std::string	name) :	
						_hitPoints(hitPoints),
						_maxHitPoints(maxHitPoints),
						_energyPoints(energyPoints),
						_maxEnergyPoints(maxEnergyPoints),
						_level(level),
						_meleeAttackDamage(meleeAttackDamage),
						_rangedAttackDamage(rangedAttackDamage),
						_armorDamageReduction(armorDamageReduction),
						_name(name)
{
	std::cout << "Father ClapTrap complete (i.e ClapTrap with all Parameters created)" << std::endl;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Father <" << this->_name << "> commits suicide (i.e. Destructor called)" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
	*this = src;
	std::cout << "A CL4G-TP unit programmed to do anything from open doors to ninja-sassinate highly important Janitory officals copied (i.e. Copy constructor called)" << " -  My name: " << this->_name << std::endl;
	return;
}

std::string ClapTrap::getName(void)
{
	return this->_name;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "A CL-Hyperion piece of metal crap that can open doors was programmed to be exactly like another CL-Hyperion piece of metal crap that can open doors (i.e Assignation operator called)" << " -  Old name: " << this->_name;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_maxHitPoints = src._maxHitPoints;
	this->_energyPoints = src._energyPoints;
	this->_maxEnergyPoints = src._maxEnergyPoints;
	this->_level = src._level;
	this->_meleeAttackDamage = src._meleeAttackDamage;
	this->_rangedAttackDamage = src._rangedAttackDamage;
	this->_armorDamageReduction = src._armorDamageReduction;
	std::cout << " ; New identity: " << this->_name << std::endl;
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "<" << this->_name << "> attacks <" << target << "> at range, causing <" << this->_rangedAttackDamage << "> points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "<" << this->_name << "> attacks <" << target << "> with melee, causing <" << this->_meleeAttackDamage << "> points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damage;
	
	if (this->_hitPoints + this->_armorDamageReduction >= amount)
		damage = amount - this->_armorDamageReduction;
	else
		damage = this->_hitPoints;
	this->_hitPoints -= damage;
	std::cout << "<" << this->_name << "> took <" << damage << "> points of damage ! Now he has " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int repairing;

	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
	{
		repairing = amount - (this->_hitPoints - this->_maxHitPoints);
		this->_hitPoints = this->_maxHitPoints;
	}
	else
		repairing = amount;
	std::cout << "<" << this->_name << "> repairs <" << repairing << "> points! Now he has " << this->_hitPoints << std::endl;
}
