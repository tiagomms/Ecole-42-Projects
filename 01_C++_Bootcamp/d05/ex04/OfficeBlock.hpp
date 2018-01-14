// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   OfficeBlock.hpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include <iostream>
#include <exception>
#include <string>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock {

public:	
	~OfficeBlock(); //Canonical
	OfficeBlock(); //Canonical

	OfficeBlock(Intern * intern, Bureaucrat * signBureaucrat, 
		Bureaucrat * execBureaucrat);

	void		setIntern(Intern * intern);
	void		setSignBureaucrat(Bureaucrat * signBureaucrat);
	void		setExecBureaucrat(Bureaucrat * execBureaucrat);
	void		doBureaucracy(std::string const & formRequest, std::string target);



	class	MissingStaff : public std::exception
	{
	public:
		virtual const char * what() const throw();

		virtual ~MissingStaff(void) throw(); //Canonical
		MissingStaff(MissingStaff const & src); //Canonical
		MissingStaff & operator=(MissingStaff const & src); //Canonical
		MissingStaff();

	private:

	};

	class	NoForm : public std::exception
	{
	public:
		virtual const char * what() const throw();
		
		virtual ~NoForm() throw(); //Canonical
		NoForm(NoForm const & src); //Canonical
		NoForm & operator=(NoForm const & src); //Canonical
		NoForm(); //Canonical

	private:

	};



private:
	OfficeBlock(OfficeBlock const & src); //Canonical		
	OfficeBlock & operator=(OfficeBlock const & src); // Canonical	
	Intern		*	_intern;
	Bureaucrat 	* 	_signBureaucrat;
	Bureaucrat 	* 	_execBureaucrat;
};

#endif
