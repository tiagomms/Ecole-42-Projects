// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 13:49:19 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 13:49:19 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap {

public:
	ScavTrap(void); //Canonical
	~ScavTrap(void); //Canonical
	ScavTrap(ScavTrap const & src); //Canonical
	ScavTrap & operator=(ScavTrap const & src); // Canonical

	ScavTrap(std::string name);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const & target);

private:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;	
	unsigned int	_level;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;
	std::string		_name;
	
	void holdingPeaWithTongue(std::string const & target);
	void doTheFour(std::string const & target);
	void drinkingCompetition(std::string const & target);
	void trainKungFuryMoves(std::string const & target);
	void burpingCompetition(std::string const & target);	
};

#endif
