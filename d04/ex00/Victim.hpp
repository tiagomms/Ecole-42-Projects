// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Victim.hpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:06:00 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim {

public:
	virtual ~Victim(void); //Canonical
	Victim(Victim const & src); //Canonical
	Victim & operator=(Victim const & src); // Canonical

	Victim(std::string name);
	std::string getName() const;
	virtual void getPolymorphed() const; 

protected:
	std::string _name;
	Victim(void); //Canonical

};

std::ostream &	operator<<( std::ostream & o, Victim const &victim);


#endif