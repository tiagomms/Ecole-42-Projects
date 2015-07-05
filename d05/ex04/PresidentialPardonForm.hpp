// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PresidentialPardonForm.hpp                                           :+:      :+:
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

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public  Form {

public:	
	~PresidentialPardonForm(void); //Canonical
	PresidentialPardonForm & operator=(PresidentialPardonForm const & src); // Canonical
	PresidentialPardonForm(PresidentialPardonForm const & src); //Canonical
	PresidentialPardonForm(std::string target);
	virtual void		execute(Bureaucrat const & executor) const;


private:
	PresidentialPardonForm(); //Canonical
	std::string					_target;	
	static const int			_PresidentialSign;
	static const int			_PresidentialExecute;
};

#endif
