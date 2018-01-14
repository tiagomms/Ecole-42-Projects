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
//   Created: 2015/06/16 17:19:30 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:19:30 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

int main()
{
	Human A;

	A.action("meleeAttack", "Bugs Bunny");
	A.action("intimidatingShout", "Cameleon");
	A.action("rangedAttack", "BipBip");
	A.action("fart", "42 cluster");
	return 0;
}