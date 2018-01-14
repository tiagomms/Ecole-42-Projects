// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 16:14:29 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 16:14:30 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int N )
{
	std::string default_names[5] = {"Lucas", "Edward", "Michelle", "Bronco", "Bullie"};
	int			random_nbr;
	srand (time(NULL));

	if (N > 0)
	{
		this->horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			random_nbr = rand() % 6;
			if (random_nbr != 5)
				(this->horde[i])._name = default_names[random_nbr];
			(this->horde[i])._type = "cannibal";
			(this->horde[i]).announce();
		}
	}
	else
		this->horde = NULL;
	return;
}

ZombieHorde::~ZombieHorde()
{
	if (this->horde)
		delete [] this->horde;
	return;
}