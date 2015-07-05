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

/*
Because filling out forms is annoying enough, it would just be cruel to ask our bureaucrats
to write them entirely by themselves. No, we’ll just have an intern do that.

You’re going to create the Intern class. The intern has no name, no grade, no defining
characteristics whatsoever, we only care that it does its job.

The intern has one important thing, the makeForm function. It takes two strings, the
first representing the name of a form, and the second one being the target for the form. It
will return, as a pointer to Form, a pointer to whichever concrete form class is represented
by the first parameter, initialized with the second parameter. It will print something like
"Intern creates <form>" to the standard output. If the requested form is not known,
print an explicit error message.


For example, this would create a RobotomyRequestForm targeted on "Bender" :
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
*/

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(NULL));
	Bureaucrat john("John", 1);
	Bureaucrat ben("Ben", 25);
	Bureaucrat julie("Julie", 72);
	Bureaucrat marco("Marco", 145);
	Bureaucrat fleminge("Fleminge", 150);

	//President TESTS	
	try {
		Form *president = new PresidentialPardonForm("Obama");
		std::cout << john << std::endl;
		std::cout << *president << std::endl;
		john.signForm(*president);
		std::cout << *president << std::endl;
		john.executeForm(*president);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	

	std::cout << std::endl;

	try {
		Form *president = new PresidentialPardonForm("Bush");
		std::cout << ben << std::endl;
		std::cout << *president << std::endl;
		ben.signForm(*president);
		std::cout << *president << std::endl;
		ben.executeForm(*president);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	//Robot TESTS
	try {
		Form *robot = new RobotomyRequestForm("Bed");
		std::cout << john << std::endl;
		std::cout << *robot << std::endl;
		john.signForm(*robot);
		std::cout << *robot << std::endl;
		john.executeForm(*robot);
		john.executeForm(*robot);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form *robot = new RobotomyRequestForm("shower");
		std::cout << julie << std::endl;
		std::cout << *robot << std::endl;
		julie.signForm(*robot);
		std::cout << *robot << std::endl;
		julie.executeForm(*robot);
		julie.executeForm(*robot);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	//Shrubbery TESTS
	try {
		Form *shrubbery = new ShrubberyCreationForm("bubble");
		std::cout << john << std::endl;
		std::cout << *shrubbery << std::endl;
		john.signForm(*shrubbery);
		std::cout << *shrubbery << std::endl;
		john.executeForm(*shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << std::endl;

	try {
		Form *shrubbery = new ShrubberyCreationForm("Monica Lewinski");
		std::cout << marco << std::endl;
		std::cout << *shrubbery << std::endl;
		marco.signForm(*shrubbery);
		std::cout << *shrubbery << std::endl;
		marco.executeForm(*shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	//fail signing paper
	try {
		Form *shrubbery = new ShrubberyCreationForm("Monica Lewinski");
		std::cout << fleminge << std::endl;
		std::cout << *shrubbery << std::endl;
		fleminge.signForm(*shrubbery);
		std::cout << *shrubbery << std::endl;
		fleminge.executeForm(*shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Intern intern;

	intern.makeForm("presidential pardon", "Obama");
	intern.makeForm("robotomy request", "Anatomy");
	intern.makeForm("shrubbery creation", "Lincoln");
	intern.makeForm("Ihih", "bullet");	

}