// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   RobotomyRequestForm.cpp                                           :+:      :+:
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

#include "RobotomyRequestForm.hpp"

const int		RobotomyRequestForm::_RobotomySign = 72;
const int		RobotomyRequestForm::_RobotomyExecute = 45;

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	Form("RobotomyRequestForm", RobotomyRequestForm::_RobotomySign, 
		RobotomyRequestForm::_RobotomyExecute)
{
	this->_target = target;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : 
	Form("RobotomyRequestForm", RobotomyRequestForm::_RobotomySign, 
		RobotomyRequestForm::_RobotomyExecute)
{
	*this = src;
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	this->_target = src._target;
	return *this;
}

void			RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > RobotomyRequestForm::_RobotomyExecute)
		throw Form::BureaucratNotClearForExecution();
	else
	{
		int fifty_fifty_chance = rand() % 2;

		std::cout << "* IIIHHHHH OOOOHHHH IIIIIIIH *\n";
		if (fifty_fifty_chance)
			std::cout << this->_target << " has been robotomized successfully\n";
		else
			std::cout << "Robotomized Form failed\n";
	}
}



//++++++++++++++++++++++++++++++//
//		Private Functions		//			
//++++++++++++++++++++++++++++++//

RobotomyRequestForm::RobotomyRequestForm() : 
	Form("RobotomyRequestForm", RobotomyRequestForm::_RobotomySign, 
		RobotomyRequestForm::_RobotomyExecute)
{
	return;
}
