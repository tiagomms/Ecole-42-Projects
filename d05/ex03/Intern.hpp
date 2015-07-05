// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Intern.hpp                                           :+:      :+:
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

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>
#include <string>

class Form;

class Intern {

public:	
	~Intern(void); //Canonical
	Intern(Intern const & src); //Canonical		
	Intern & operator=(Intern const & src); // Canonical

	Intern();

	Form *	makeForm(std::string const & formName, std::string target);


private:

};

#endif
