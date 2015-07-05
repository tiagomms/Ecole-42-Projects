// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 16:43:34 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 16:43:35 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() :	ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, "NinjaTrap Clone")
{
	std::cout << "The inner workings of my NinjaTrap monicidal cloned apparatus complete (i.e. Default constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string name) :	ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, name)
{
	std::cout << "The inner workings of my NinjaTrap unique monicidal apparatus complete (i.e Parameter constructor created)" << " -  My name: " << this->_name << std::endl;
	return;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap Merciless killing machine <" << this->_name << "> commits suicide (i.e. Destructor called)" << std::endl;
	return;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src)
{
	*this = src;
	std::cout << "A NinjaTrap NJ4G-TP unit programmed to do anything from open doors to ninja-sassinate highly important Janitory officals copied (i.e. Copy constructor called)" << " -  My name: " << this->_name << std::endl;
	return;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & src)
{
	std::cout << "A NJ-Hyperion piece of metal crap that can open doors was programmed to be exactly like another NJ-Hyperion piece of metal crap that can open doors (i.e Assignation operator called)" << " -  Old name: " << this->_name;
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

void NinjaTrap::ninjaBackFlipKick(ClapTrap & target)
{
	std::cout << "NJ4G-TP <" << this->_name << "> ninjas <" << target.getName() << "> with a BackFlip Kick!" << std::endl;
	target.takeDamage(20);
}

void NinjaTrap::ninjaSex(ClapTrap & target)
{
	std::cout << "NJ4G-TP <" << this->_name << "> ninjas <" << target.getName() << "> with ninja Sex. He feels raped but it doesn't know what it him... Meanwhile the ninja gets life" << std::endl;
	this->beRepaired(10);
}

void NinjaTrap::ninjaHattori(ClapTrap & target)
{
	std::cout << "NJ4G-TP <" << this->_name << "> ninjas <" << target.getName() << "> the Ninja Hattori song, the highest pitch song ever! He is deaf now..." << std::endl;
	target.takeDamage(50);
}

void NinjaTrap::ninjaTheWayOut(ClapTrap & target)
{
	std::cout << "NJ4G-TP <" << this->_name << "> ninjas <" << target.getName() << "> the Way Out with his shoes. Talking about being unpleasant..." << std::endl;
}

void NinjaTrap::ninjaShuriken(ClapTrap & target)
{
	std::cout << "NJ4G-TP <" << this->_name << "> ninjas <" << target.getName() << "> a shuriken right to the heart! He is dead" << std::endl;
	target.takeDamage(200);
}


void NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	int			random_nbr;
	void (NinjaTrap::*function_Array[5])(ClapTrap &) = {NULL};

	if (this->_energyPoints < 25)
	{
		std::cout << "Let <" << this->_name << "> recharge! Out of battery... =(" << std::endl;
		return;
	}
	function_Array[0] = &NinjaTrap::ninjaBackFlipKick;
	function_Array[1] = &NinjaTrap::ninjaSex;
	function_Array[2] = &NinjaTrap::ninjaHattori;
	function_Array[3] = &NinjaTrap::ninjaTheWayOut;
	function_Array[4] = &NinjaTrap::ninjaShuriken;
	this->_energyPoints -= 25;
	random_nbr = rand() % 5;
	return (this->*function_Array[random_nbr])(target);
}
