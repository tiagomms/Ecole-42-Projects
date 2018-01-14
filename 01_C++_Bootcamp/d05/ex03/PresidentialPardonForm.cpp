// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PresidentialPardonForm.cpp                                           :+:      :+:
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

#include "PresidentialPardonForm.hpp"

const int		PresidentialPardonForm::_PresidentialSign = 25;
const int		PresidentialPardonForm::_PresidentialExecute = 5;

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	Form("PresidentialPardonForm", PresidentialPardonForm::_PresidentialSign, 
		PresidentialPardonForm::_PresidentialExecute)
{
	this->_target = target;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : 
	Form("PresidentialPardonForm", PresidentialPardonForm::_PresidentialSign, 
		PresidentialPardonForm::_PresidentialExecute)
{
	*this = src;
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	this->_target = src._target;
	return *this;
}

void			PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > PresidentialPardonForm::_PresidentialExecute)
		throw Form::BureaucratNotClearForExecution();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox.\n";
}


//++++++++++++++++++++++++++++++//
//		Private Functions		//			
//++++++++++++++++++++++++++++++//

PresidentialPardonForm::PresidentialPardonForm() : 
	Form("PresidentialPardonForm", PresidentialPardonForm::_PresidentialSign, 
		PresidentialPardonForm::_PresidentialExecute)
{
	return;
}
