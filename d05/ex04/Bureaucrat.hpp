// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Bureaucrat.hpp                                           :+:      :+:
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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {

public:	
	~Bureaucrat(void); //Canonical
	Bureaucrat(Bureaucrat const & src); //Canonical		
	Bureaucrat & operator=(Bureaucrat const & src); // Canonical

	Bureaucrat(std::string name, int grade);
	std::string const &	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form & form);
	void				executeForm(Form const & form) const;


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
	Bureaucrat(); //Canonical
	const	std::string _name;
	int		_grade;
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const &bureau);

#endif
