// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Intern.cpp                                           :+:      :+:
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

#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() 
{
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return;
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	return *this;
}


Form * Intern::makeForm(std::string const & formName, std::string target)
{
	Form *form;
	std::string formOptions[3] = 
		{ "presidential pardon" , "robotomy request" , "shrubbery creation" };
	if (!formName.compare(formOptions[0]))
		form = new PresidentialPardonForm(target);
	else if (!formName.compare(formOptions[1]))
		form = new RobotomyRequestForm(target);
	else if (!formName.compare(formOptions[2]))
		form = new ShrubberyCreationForm(target);	
	else
		form = NULL;

	if (form)
		std::cout << "Intern creates " << *form << std::endl;
	else
		std::cout << "Unknown Form requested to Intern - " << formName << std::endl;
	return form;
}
