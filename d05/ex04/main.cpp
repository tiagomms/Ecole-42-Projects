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
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

/*
valid form names: "presidential pardon" ,"robotomy request" ,"shrubbery creation"
levels for bureaucrats: 1 - 150 (highest - lowest)
set any of these bureaucrats or interns null before the function do bureaucracy

*/

int main()
{	
	try
	{
		Intern * idiotOne = new Intern;
		Bureaucrat * hermes = new Bureaucrat("Hermes Conrad", 1);
		Bureaucrat * bob = new Bureaucrat("Bobby Bobson", 30);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSignBureaucrat(bob);
		ob.setExecBureaucrat(hermes);
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << ". One of these Bureaucrats is a CON\n";
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << ". One of these Bureaucrats is a CON\n";
	}
	catch (OfficeBlock::MissingStaff & e)
	{
		std::cout << e.what() << ". The Job cannot be complete.\n";
	}
	catch (OfficeBlock::NoForm & e)
	{
		std::cout << e.what() << " FIRE HIM!!!\n";
	}
	catch (Form::BureaucratNotClearForSign & e)
	{
		std::cout << e.what() << ". Get a higher ranking Signer Bureaucrat\n"; 
	}
	catch (Form::BureaucratNotClearForExecution & e)
	{
		std::cout << e.what() << ". Get a higher ranking Executive Bureaucrat\n"; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ". Something FISHY IS HAPPENING\n";
	}
}
