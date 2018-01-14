// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   OfficeBlock.cpp                                           :+:      :+:
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

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : 
		_intern(NULL), 
		_signBureaucrat(NULL), 
		_execBureaucrat(NULL)
{
		return;
}

OfficeBlock::OfficeBlock(Intern * intern, Bureaucrat * signBureaucrat, 
		Bureaucrat * execBureaucrat) : _intern(intern), 
		_signBureaucrat(signBureaucrat), _execBureaucrat(execBureaucrat)
{
	return;
}

void			OfficeBlock::setIntern(Intern * intern)
{
	this->_intern = intern;
}

void			OfficeBlock::setSignBureaucrat(Bureaucrat * signBureaucrat)
{
	this->_signBureaucrat = signBureaucrat;
}

void			OfficeBlock::setExecBureaucrat(Bureaucrat * execBureaucrat)
{
	this->_execBureaucrat = execBureaucrat;
}




void			OfficeBlock::doBureaucracy(std::string const & formRequest,
 std::string target)
{
	if (!this->_intern || !this->_signBureaucrat || !this->_execBureaucrat)
		throw OfficeBlock::MissingStaff();
	Form * newform = this->_intern->makeForm(formRequest, target);
	if (!newform)
		throw  OfficeBlock::NoForm();
	else
	{
		this->_signBureaucrat->signForm(*newform);
		this->_execBureaucrat->executeForm(*newform);
	}
}



const char * OfficeBlock::MissingStaff::what() const throw()
{
	return "At least a Staff is missing";
}

const char * OfficeBlock::NoForm::what() const throw()
{
	return "Unknown Form. It is the Intern's fault!";
}


OfficeBlock::~OfficeBlock(void)
{
	return;
}

OfficeBlock::OfficeBlock(OfficeBlock const & src)
{
	*this = src;
	return;
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const & src)
{
	this->_intern = src._intern;
	this->_signBureaucrat = src._signBureaucrat;
	this->_execBureaucrat = src._execBureaucrat;
	return *this;
}

//++++++++++++++++++++++++++++++//
//		Errors Functions		//			
//++++++++++++++++++++++++++++++//


OfficeBlock::MissingStaff::~MissingStaff() throw()
{
	return;
}

OfficeBlock::MissingStaff::MissingStaff(MissingStaff const & src)
{
	*this = src;
}

OfficeBlock::MissingStaff & OfficeBlock::MissingStaff::operator=(MissingStaff const & src)
{
	*this = src;
	return *this;
}

OfficeBlock::MissingStaff::MissingStaff()
{
	return;
}




OfficeBlock::NoForm::~NoForm() throw()
{
	return;
}

OfficeBlock::NoForm::NoForm(NoForm const & src)
{
	*this = src;
}

OfficeBlock::NoForm & OfficeBlock::NoForm::operator=(NoForm const & src)
{
	*this = src;
	return *this;
}

OfficeBlock::NoForm::NoForm()
{
	return;
}
