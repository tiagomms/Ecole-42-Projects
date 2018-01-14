// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ShrubberyCreationForm.cpp                                           :+:      :+:
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

#include "ShrubberyCreationForm.hpp"

const int		ShrubberyCreationForm::_ShrubberySign = 145;
const int		ShrubberyCreationForm::_ShrubberyExecute = 137;

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	Form("ShrubberyCreationForm", ShrubberyCreationForm::_ShrubberySign, 
		ShrubberyCreationForm::_ShrubberyExecute)
{
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : 
	Form("ShrubberyCreationForm", ShrubberyCreationForm::_ShrubberySign, 
		ShrubberyCreationForm::_ShrubberyExecute)
{
	*this = src;
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	this->_target = src._target;
	return *this;
}

void			ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > ShrubberyCreationForm::_ShrubberyExecute)
		throw Form::BureaucratNotClearForExecution();
	else
	{
		std::string filename = this->_target + "_shrubbery";
		
		std::ofstream out(filename);
		out << "    X\n";
		out << "   XXX\n";
		out << "  XXXXX\n";
		out << " XXXXXXX\n";
		out << "    X\n";
		out.close();
	}
}

//++++++++++++++++++++++++++++++//
//		Private Functions		//			
//++++++++++++++++++++++++++++++//

ShrubberyCreationForm::ShrubberyCreationForm() : 
	Form("ShrubberyCreationForm", ShrubberyCreationForm::_ShrubberySign, 
		ShrubberyCreationForm::_ShrubberyExecute)
{
	return;
}
