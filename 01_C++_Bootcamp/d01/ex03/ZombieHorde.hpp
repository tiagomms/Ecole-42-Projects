// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 16:14:39 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 16:14:40 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class ZombieHorde
{
public:
	ZombieHorde( int N );
	~ZombieHorde();

	Zombie *horde;
	
};

#endif
