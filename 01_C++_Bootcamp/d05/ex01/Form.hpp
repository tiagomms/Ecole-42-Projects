// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Form.hpp                                           :+:      :+:
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

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {

public:	
	~Form(void); //Canonical
	Form & operator=(Form const & src); // Canonical
	Form(Form const & src); //Canonical

	Form(std::string name, int gradeSign, int gradeExecute);
	std::string const &	getName() const;
	int					getGradeSign() const;
	int					getGradeExecute() const;
	bool				getIsSigned() const;
	void				beSigned(Bureaucrat const & bureaucrat);
	
	class	GradeTooHighException : public std::exception
	{

	public:
		virtual const char * what() const throw();

		virtual ~GradeTooHighException(void) throw(); //Canonical
		GradeTooHighException(GradeTooHighException const & src); //Canonical
		GradeTooHighException & operator=(GradeTooHighException const & src); //Canonical
		GradeTooHighException();
	private:

	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw();
		
		virtual ~GradeTooLowException() throw(); //Canonical
		GradeTooLowException(GradeTooLowException const & src); //Canonical
		GradeTooLowException & operator=(GradeTooLowException const & src); //Canonical
		GradeTooLowException(); //Canonical

	private:

	};



private:
	Form(); //Canonical
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExecute;
};

std::ostream &	operator<<( std::ostream & o, Form const &form);

#endif
