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

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat john = Bureaucrat("John", 15);
		std::cout << john << std::endl;
		john.decrementGrade();
		std::cout << john << std::endl;
		john.incrementGrade();
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat ben = Bureaucrat("Ben", 1);
		std::cout << ben << std::endl;
		ben.incrementGrade();
		std::cout << ben << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat julie = Bureaucrat("Julie", 0);
		std::cout << julie << std::endl;
		julie.incrementGrade();
		std::cout << julie << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat marco = Bureaucrat("Marco", 150);
		std::cout << marco << std::endl;
		marco.decrementGrade();
		std::cout << marco << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat fleminge = Bureaucrat("Fleminge", 156);
		std::cout << fleminge << std::endl;
		fleminge.decrementGrade();
		std::cout << fleminge << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}