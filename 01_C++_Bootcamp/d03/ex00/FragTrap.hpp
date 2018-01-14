// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   FragTrap.hpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 10:15:47 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 10:15:48 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap {

public:
	FragTrap(void); //Canonical
	~FragTrap(void); //Canonical
	FragTrap(FragTrap const & src); //Canonical
	FragTrap & operator=(FragTrap const & src); // Canonical

	FragTrap(std::string name);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);

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

	void faRT(std::string const & target);
	void ChuckNorrisRoundHouseKick(std::string const & target);
	void lick(std::string const & target);
	
};

#endif