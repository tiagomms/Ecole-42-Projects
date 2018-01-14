// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   main.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 10:15:54 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 10:15:55 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	FragTrap A;
	std::cout << std::endl;
	FragTrap B("The Original Claptrap");
	std::cout << std::endl;
	ScavTrap C;
	std::cout << std::endl;	
	ScavTrap D("Chat");
	std::cout << std::endl;
	srand (time(NULL));

	D.takeDamage(20);
	B.meleeAttack("Claptrap clone");
	A.takeDamage(30);
	A.rangedAttack("Chat");	
	std::cout << std::endl;
	A.vaulthunter_dot_exe("The Original Claptrap");
	A.vaulthunter_dot_exe("Chat");
	std::cout << std::endl;	
	D.takeDamage(100);
	D.takeDamage(100);	
	std::cout << std::endl;	
	D = C;
	std::cout << std::endl;	
	D.takeDamage(20);
	D.beRepaired(10);
	D.beRepaired(20);
	std::cout << std::endl;

	D.challengeNewcomer("The Original ClapTrap");
	D.challengeNewcomer("The Original ClapTrap");
	D.challengeNewcomer("The Original ClapTrap");		

	std::cout << std::endl;
	return 0;
}