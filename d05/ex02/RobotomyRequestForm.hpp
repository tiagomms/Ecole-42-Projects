// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   RobotomyRequestForm.hpp                                           :+:      :+:
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

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public  Form {

public:	
	~RobotomyRequestForm(void); //Canonical
	RobotomyRequestForm & operator=(RobotomyRequestForm const & src); // Canonical
	RobotomyRequestForm(RobotomyRequestForm const & src); //Canonical
	RobotomyRequestForm(std::string target);
	virtual void		execute(Bureaucrat const & executor) const;


private:
	RobotomyRequestForm(); //Canonical
	std::string					_target;	
	static const int			_RobotomySign;
	static const int			_RobotomyExecute;
};

#endif

