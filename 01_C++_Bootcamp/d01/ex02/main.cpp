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
//   Created: 2015/06/16 14:36:21 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 14:36:21 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void)
{
	Zombie *A;
	Zombie *B;
	Zombie *C;
	Zombie *D;
	ZombieEvent event;

	A = event.newZombie("Unicorn3000");
	B = event.newZombie("");
	C = event.randomChump();
	D = event.randomChump();

	delete B;
	delete D;
	delete A;
	delete C;

	return 0;			
}