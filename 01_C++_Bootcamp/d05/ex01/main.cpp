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
Now that we have bureaucrats, better give them something to do with their time.
What better occupation than a stack of forms to fill out ?

Make a Form class. It has a name, a boolean indicating whether it is signed (at
the beginning, it’s not), a grade required to sign it, and a grade required to execute it.
The name and grades are constant, and all these attributes are private (not protected).
The grades are subject to the same constraints as in the Bureaucrat, and exceptions
will be thrown if any of them are out of bounds, Form::GradeTooHighException and
Form::GradeTooLowException.

Same as before, make getters for all attributes, and an overload of the << operator
to ostream that completely describes the state of the form.

You will also add a beSigned function that takes a Bureaucrat, and makes the form
signed if the bureaucrat’s grade is high enough. Always remember, grade 1 is better than
grade 2. If the grade is too low, throw a Form::GradeTooLowException.

Also add a signForm function to the Bureaucrat. If the signing is successful, it will
print something like "<bureaucrat> signs <form", otherwise it will print something
like "<bureaucrat> cannot sign <form> because <reason>".
Add whatever’s needed to test this to your main.

*/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat john("John", 1);
	Bureaucrat julie("Julie", 150);
	
	try {
		Form residence("Residence", 16, 17);
		std::cout << john << std::endl;
		std::cout << residence << std::endl;
		john.signForm(residence);
		std::cout << residence << std::endl;		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	

	std::cout << std::endl;
	
	try {
		Form residence("Residence", 16, 17);
		std::cout << julie << std::endl;
		std::cout << residence << std::endl;	
		julie.signForm(residence);

		
		std::cout << residence << std::endl;
		julie.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Form irs = Form("IRS", 1, 151);
		std::cout << irs << std::endl;
		julie.signForm(irs);
		std::cout << irs << std::endl;
		julie.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Form water = Form("water", 0, 150);
		std::cout << water << std::endl;
		julie.signForm(water);
		std::cout << water << std::endl;
		julie.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}