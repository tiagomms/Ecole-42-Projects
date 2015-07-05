// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 14:35:39 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 14:35:53 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(Zombie & zombie)
{
	zombie._type = "cannibal";
}

Zombie	*ZombieEvent::newZombie( std::string name )
{
	Zombie * new_zombie;

	if (name == "")
		new_zombie = new Zombie;
	else
		new_zombie = new Zombie(name);
	ZombieEvent::setZombieType(*new_zombie);
	std::cout << new_zombie->_name << " was created of type " << 
	new_zombie->_type << ".\n";	
	return new_zombie;
}

Zombie	*ZombieEvent::randomChump ( void )
{
	std::string default_names[5] = {"Lucas", "Edward", "Michelle", "Bronco", "Bullie"};
	srand (time(NULL));
	int			random_nbr;
	Zombie		*rand_zomb;

	random_nbr = rand() % 6;
	if (random_nbr == 5)
		rand_zomb = ZombieEvent::newZombie("");
	else
		rand_zomb = ZombieEvent::newZombie(default_names[random_nbr]);
	rand_zomb->announce();
	return rand_zomb;
}
