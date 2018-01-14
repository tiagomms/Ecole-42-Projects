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

int main(void)
{
	FragTrap A;
	FragTrap B("The Original Claptrap");
	FragTrap C("BabyChuck");
	FragTrap D("Jack");
	FragTrap E("PussyCat");
	std::cout << std::endl;
	FragTrap F(A);
	std::cout << std::endl;
	srand (time(NULL));

	A.rangedAttack("BabyChuck");
	C.takeDamage(20);
	B.meleeAttack("Claptrap clone");
	A.takeDamage(30);
	std::cout << std::endl;
	E.vaulthunter_dot_exe("Jack");
	E.vaulthunter_dot_exe("Jack");
	E.vaulthunter_dot_exe("Jack");
	std::cout << std::endl;	
	D.takeDamage(100);
	D.takeDamage(100);	
	std::cout << std::endl;	
	D = E;
	std::cout << std::endl;	
	D.takeDamage(20);
	D.beRepaired(10);
	D.beRepaired(20);
	std::cout << std::endl;	
	return 0;
}