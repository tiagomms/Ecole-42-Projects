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
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	SuperTrap A;
	std::cout << std::endl;		
	FragTrap B("The Original Claptrap");
	std::cout << std::endl;	
	ScavTrap D("Chat");
	std::cout << std::endl;
	SuperTrap F("SuperNinja");
	std::cout << std::endl;
	std::cout << std::endl;	
	std::cout << "++++++++++++++++++++++++ ATTACK TIME ++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;				
	srand (time(NULL));

	A.ninjaShoebox(D);
	std::cout << std::endl;	

	A.ninjaShoebox(B);
	std::cout << std::endl;	

	A.ninjaShoebox(F);
	std::cout << std::endl;	
	
	A.vaulthunter_dot_exe(F.getName());
	std::cout << std::endl;	
	A.vaulthunter_dot_exe(D.getName());
	std::cout << std::endl;	


	A.meleeAttack("Claptrap clone");
	A.rangedAttack("Claptrap clone");
	A.takeDamage(100);
	std::cout << std::endl;	
	A = F;
	std::cout << std::endl;	
	A.beRepaired(200);
	std::cout << std::endl;	
	std::cout << std::endl;
	std::cout << "++++++++++++++++++++++++ DESTRUCTOR TIME ++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;			
	return 0;
}