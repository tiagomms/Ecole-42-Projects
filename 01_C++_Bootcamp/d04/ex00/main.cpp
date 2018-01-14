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
//   Created: 2015/06/19 14:05:25 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"
#include "Peon.hpp"
#include "Sorcerer.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << std::endl << "+++++++++Extra TEXTS+++++++++" << std::endl << std::endl;
	Victim matt("Matt");
	Peon ben("Ben");
	Victim *Super_Jim = new Peon("Super_Jim");//
	std::cout << robert << matt << ben;//
	std::cout << *Super_Jim;//

	std::cout << std::endl << "+++++++++ matt = ben +++++++++" << std::endl << std::endl;
	matt = ben;//

	std::cout << robert << matt << ben;//
	robert.polymorph(matt);//
	robert.polymorph(ben);//
	robert.polymorph(*Super_Jim);//
	delete Super_Jim;
	return 0;
}