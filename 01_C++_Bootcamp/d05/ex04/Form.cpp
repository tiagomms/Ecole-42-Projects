// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Form.cpp                                           :+:      :+:
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

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeSign, int gradeExecute) : 
	_name(name), 
	_isSigned(false), 
	_gradeSign(gradeSign), 
	_gradeExecute(gradeExecute)
{
	if (this->getGradeSign() < 1 || this->getGradeExecute() < 1)
		throw Form::GradeTooHighException();
	else if (this->getGradeSign() > 150 || this->getGradeExecute() > 150)
		throw Form::GradeTooLowException();
	return;
}

std::string const & Form::getName() const
{
	return this->_name;
}

int			Form::getGradeSign() const
{
	return this->_gradeSign;
}

int			Form::getGradeExecute() const
{
	return this->_gradeExecute;
}

bool			Form::getIsSigned() const
{
	return this->_isSigned;
}

void			Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_isSigned)
		return;
	if (this->getGradeSign() < bureaucrat.getGrade())
		throw Form::BureaucratNotClearForSign();
	else
		this->_isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High for Form to be Signed/Executed";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low for Form to be Signed/Executed";
}

const char * Form::BureaucratNotClearForSign::what() const throw()
{
	return "Bureaucrat without the clearance needed for Signing";
}

const char * Form::BureaucratNotClearForExecution::what() const throw()
{
	return "Bureaucrat without the clearance needed for Executing";
}


Form::~Form(void)
{
	return;
}

Form::Form(Form const & src) : _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	*this = src;
	return;
}

Form & Form::operator=(Form const & src)
{
	this->_isSigned = src.getIsSigned();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Form const &form)
{
	o << "Form: " << form.getName() << ", Grade Required to be Signed: " 
		<< form.getGradeSign() << ", Grade Required to be Executed: " 
		<< form.getGradeExecute() << ". Is Signed? " 
		<< form.getIsSigned() << ".";
	return o;
}


//++++++++++++++++++++++++++++++//
//		Private Functions		//			
//++++++++++++++++++++++++++++++//

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	return;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & src)
{
	*this = src;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException()
{
	return;
}



Form::GradeTooLowException::~GradeTooLowException() throw()
{
	return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & src)
{
	*this = src;
	return *this;
}

Form::GradeTooLowException::GradeTooLowException()
{
	return;
}



Form::BureaucratNotClearForSign::~BureaucratNotClearForSign() throw()
{
	return;
}

Form::BureaucratNotClearForSign::BureaucratNotClearForSign(BureaucratNotClearForSign const & src)
{
	*this = src;
}

Form::BureaucratNotClearForSign & Form::BureaucratNotClearForSign::operator=(BureaucratNotClearForSign const & src)
{
	*this = src;
	return *this;
}

Form::BureaucratNotClearForSign::BureaucratNotClearForSign()
{
	return;
}



Form::BureaucratNotClearForExecution::~BureaucratNotClearForExecution() throw()
{
	return;
}

Form::BureaucratNotClearForExecution::BureaucratNotClearForExecution(BureaucratNotClearForExecution const & src)
{
	*this = src;
}

Form::BureaucratNotClearForExecution & Form::BureaucratNotClearForExecution::operator=(BureaucratNotClearForExecution const & src)
{
	*this = src;
	return *this;
}

Form::BureaucratNotClearForExecution::BureaucratNotClearForExecution()
{
	return;
}



