// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 13:49:07 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 13:49:08 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :	ClapTrap(100, 100, 50, 50, 1, 20, 15, 3, "ScavTrap Clone")
{
	std::cout << "The inner workings of my ScavTrap monicidal cloned apparatus complete (i.e. Default constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) :	ClapTrap(100, 100, 50, 50, 1, 20, 15, 3, name)
{
	std::cout << "The inner workings of my ScavTrap unique monicidal apparatus complete (i.e Parameter constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Merciless killing machine <" << this->_name << "> commits suicide (i.e. Destructor called)" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src)
{
	*this = src;
	std::cout << "A ScavTrap SC4G-TP unit programmed to do anything from open doors to ninja-sassinate highly important Janitory officals copied (i.e. Copy constructor called)" << " -  My name: " << this->_name << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << "A SC-Hyperion piece of metal crap that can open doors was programmed to be exactly like another SC-Hyperion piece of metal crap that can open doors (i.e Assignation operator called)" << " -  Old name: " << this->_name;
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

void ScavTrap::holdingPeaWithTongue(std::string const & target)
{
	std::cout << "SC4G-TP <" << this->_name << "> challenges <" << target << "> to hold a pea with his tongue without eating it!" << std::endl;
}

void ScavTrap::doTheFour(std::string const & target)
{
	std::cout << "SC4G-TP <" << this->_name << "> challenges <" << target << "> to do the Four in front of a cop." << std::endl;
}

void ScavTrap::drinkingCompetition(std::string const & target)
{
	std::cout << "SC4G-TP <" << this->_name << "> challenges <" << target << "> to drink more alcohol than him (ScavTrap uses alcohol as fuel...)" << std::endl;
}

void ScavTrap::trainKungFuryMoves(std::string const & target)
{
	std::cout << "SC4G-TP <" << this->_name << "> challenges <" << target << "> with getting out of a car while high-flying and shoot a Nazi Pinball machine!" << std::endl;
}

void ScavTrap::burpingCompetition(std::string const & target)
{
	std::cout << "SC4G-TP <" << this->_name << "> challenges <" << target << "> to do a Burping Competition!" << std::endl;
}


void ScavTrap::challengeNewcomer(std::string const & target)
{
	int			random_nbr;
	void (ScavTrap::*function_Array[5])(std::string const & ) = {NULL};

	if (this->_energyPoints < 25)
	{
		std::cout << "Let <" << this->_name << "> recharge! Out of battery... =(" << std::endl;
		return;
	}
	function_Array[0] = &ScavTrap::holdingPeaWithTongue;
	function_Array[1] = &ScavTrap::doTheFour;
	function_Array[2] = &ScavTrap::drinkingCompetition;
	function_Array[3] = &ScavTrap::trainKungFuryMoves;
	function_Array[4] = &ScavTrap::burpingCompetition;
	this->_energyPoints -= 25;
	random_nbr = rand() % 5;
	return (this->*function_Array[random_nbr])(target);
}
