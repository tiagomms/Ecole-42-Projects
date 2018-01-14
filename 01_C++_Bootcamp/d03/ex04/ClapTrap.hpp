// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:
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

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

public:
	ClapTrap(void); //Canonical
	~ClapTrap(void); //Canonical
	ClapTrap(ClapTrap const & src); //Canonical
	ClapTrap & operator=(ClapTrap const & src); // Canonical
	
	ClapTrap( unsigned int hitPoints,
		unsigned int	maxHitPoints,
		unsigned int 	energyPoints,	
		unsigned int 	maxEnergyPoints,
		unsigned int	level,	
		unsigned int	meleeAttackDamage,	
		unsigned int	rangedAttackDamage,
		unsigned int	armorDamageReduction,
		std::string		name);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string		getName() const;
	unsigned int 	getHitPoints() const;
	unsigned int 	getMaxHitPoints() const;
	unsigned int 	getEnergyPoints() const;
	unsigned int 	getMaxEnergyPoints() const;
	unsigned int 	getLevel() const;
	unsigned int 	getMeleeAttackDamage() const;
	unsigned int 	getRangedAttackDamage() const;
	unsigned int 	getArmorDamageReduction() const;

protected:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;	
	unsigned int	_level;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;
	std::string		_name;

	void	setName(std::string);
	void	setHitPoints(unsigned int);
	void	setMaxHitPoints(unsigned int);
	void	setEnergyPoints(unsigned int);
	void	setMaxEnergyPoints(unsigned int);
	void	setLevel(unsigned int);
	void	setMeleeAttackDamage(unsigned int);
	void	setRangedAttackDamage(unsigned int);
	void	setArmorDamageReduction(unsigned int);	


};

#endif