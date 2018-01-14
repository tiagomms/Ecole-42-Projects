// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Bureaucrat.cpp                                           :+:      :+:
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

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return;
}

std::string const & Bureaucrat::getName() const
{
	return this->_name;
}

int				Bureaucrat::getGrade() const
{
	return this->_grade;
}

void			Bureaucrat::incrementGrade()
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void			Bureaucrat::decrementGrade()
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void			Bureaucrat::signForm(Form & form)
{
	form.beSigned(*this);
	std::cout << this->getName() << " signs " << form.getName() << std::endl;	
}

void			Bureaucrat::executeForm(Form const & form) const
{
	std::cout << this->getName() << " executes " << form.getName() << std::endl;
	form.execute(*this);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High, YOU CHEATER!";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low! Who are you trying to screw over???";
}



Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	return;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
//	this->_name = src.getName();
	this->_grade = src.getGrade();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const &bureau)
{
	o << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return o;
}


//++++++++++++++++++++++++++++++//
//		Private Functions		//			
//++++++++++++++++++++++++++++++//

Bureaucrat::Bureaucrat() 
{
	return;
}


Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & src)
{
	*this = src;
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	return;
}



Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & src)
{
	*this = src;
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	return;
}






