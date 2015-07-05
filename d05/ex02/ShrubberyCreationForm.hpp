// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ShrubberyCreationForm.hpp                                           :+:      :+:
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

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public  Form {

public:	
	~ShrubberyCreationForm(void); //Canonical
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src); // Canonical
	ShrubberyCreationForm(ShrubberyCreationForm const & src); //Canonical
	ShrubberyCreationForm(std::string target);
	virtual void		execute(Bureaucrat const & executor) const;


private:
	ShrubberyCreationForm(); //Canonical
	std::string					_target;	
	static const int			_ShrubberySign;
	static const int			_ShrubberyExecute;
};

#endif
