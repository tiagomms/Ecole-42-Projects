// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 14:35:50 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 14:35:55 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class ZombieEvent {

public:
	void	setZombieType(Zombie & );
	Zombie	*newZombie( std::string );
	Zombie	*randomChump();
};

#endif