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
//   Created: 2015/06/19 14:05:44 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "easyfind.hpp"

/*
An easy one to start off on the right foot ...

Make a template function called easyfind, templated on a type T, that takes a T
and an int.

Assume the T is a container of int, and find the first occurence of the second 
parameter in the first parameter.

If it can’t be found, handle the error either using an exception or using an error 
return value. Take ideas from how standard containers work.

Of course, you will provide a main function that tests it thoroughly.
*/

int main()
{
	std::vector<int> container;
	std::list<int>   container2;

	int i = 0;

	while (i < 10)
	{
		container.push_back(5 * (i + 1));
		container2.push_back(-2 * (i + 1));
		i++;
	}

	try {
		easyfind(container, 5);
	}
	catch (std::exception & e) {
		std::cout << "Error: 5 is not in the container" << std::endl;
	}

	try {
		easyfind(container, 35);
	}
	catch (std::exception & e) {
		std::cout << "Error: 35 is not in the container" << std::endl;
	}

	try {
		easyfind(container, 55);
	}
	catch (std::exception & e) {
		std::cout << "Error: 55 is not in the container" << std::endl;
	}

	std::cout << std::endl <<"container2 now" << std::endl;

	try {
		easyfind(container2, -1);
	}
	catch (std::exception & e) {
		std::cout << "Error: -1 is not in the container" << std::endl;
	}

	try {
		easyfind(container2, -4);
	}
	catch (std::exception & e) {
		std::cout << "Error: 35 is not in the container" << std::endl;
	}

	try {
		easyfind(container2, -6);
	}
	catch (std::exception & e) {
		std::cout << "Error: 55 is not in the container" << std::endl;
	}

	return 0;
}