// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   FragTrap.cpp                                       :+:      :+:
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

#include "FragTrap.hpp"

FragTrap::FragTrap() :	_hitPoints(100),
						_maxHitPoints(100),
						_energyPoints(100),
						_maxEnergyPoints(100),
						_level(1),
						_meleeAttackDamage(30),
						_rangedAttackDamage(20),
						_armorDamageReduction(5),
						_name("FragTrap Clone")
{
	std::cout << "The inner workings of my FragTrap monicidal cloned apparatus complete (i.e. Default constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) :	
						_hitPoints(100),
						_maxHitPoints(100),
						_energyPoints(100),
						_maxEnergyPoints(100),
						_level(1),
						_meleeAttackDamage(30),
						_rangedAttackDamage(20),
						_armorDamageReduction(5),
						_name(name)
{
	std::cout << "The inner workings of my FragTrap unique monicidal apparatus complete (i.e Parameter constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Merciless killing machine <" << this->_name << "> commits suicide (i.e. Destructor called)" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & src)
{
	*this = src;
	std::cout << "A FR4G-TP unit programmed to do anything from open doors to ninja-sassinate highly important Janitory officals copied (i.e. Copy constructor called)" << " -  My name: " << this->_name << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	std::cout << "A FR-Hyperion piece of metal crap that can open doors was programmed to be exactly like another FR-Hyperion piece of metal crap that can open doors (i.e Assignation operator called)" << " -  Old name: " << this->_name;
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

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target << "> at range, causing <" << this->_rangedAttackDamage << "> points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target << "> with melee, causing <" << this->_meleeAttackDamage << "> points of damage !" << std::endl;
}

void FragTrap::faRT(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target << "> with a fart! Now that is just disgusting! No damage, only rudeness!" << std::endl;
}

void FragTrap::ChuckNorrisRoundHouseKick(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target << "> with a RoundHouse Kick! Infinite points of damage!" << std::endl;
}

void FragTrap::lick(std::string const & target)
{
	std::cout << "FR4G-TP <" << this->_name << "> starts to lick and make out with <" << target << ">! Oh Boy!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	unsigned int damage;
	
	if (this->_hitPoints + this->_armorDamageReduction >= amount)
		damage = amount - this->_armorDamageReduction;
	else
		damage = this->_hitPoints;
	this->_hitPoints -= damage;
	std::cout << "FR4G-TP <" << this->_name << "> took <" << damage << "> points of damage ! Now he has " << this->_hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
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
	std::cout << "FR4G-TP <" << this->_name << "> repairs <" << repairing << "> points! Now he has " << this->_hitPoints << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int			random_nbr;
	void (FragTrap::*function_Array[5])(std::string const & ) = {NULL};

	if (this->_energyPoints < 25)
	{
		std::cout << "Let <" << this->_name << "> recharge! Out of battery... =(" << std::endl;
		return;
	}
	function_Array[0] = &FragTrap::meleeAttack;
	function_Array[1] = &FragTrap::rangedAttack;
	function_Array[2] = &FragTrap::faRT;
	function_Array[3] = &FragTrap::ChuckNorrisRoundHouseKick;
	function_Array[4] = &FragTrap::lick;
	this->_energyPoints -= 25;
	random_nbr = rand() % 5;
	return (this->*function_Array[random_nbr])(target);
}