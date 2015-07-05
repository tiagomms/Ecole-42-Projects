// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:02 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:11 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {

public:
	~Sorcerer(void); //Canonical
	Sorcerer(Sorcerer const & src); //Canonical
	Sorcerer & operator=(Sorcerer const & src); // Canonical

	Sorcerer(std::string name, std::string title);
	std::string getName() const;
	std::string getTitle() const;
	void polymorph(Victim const &victim);

private:
	std::string _name;
	std::string _title;	
	Sorcerer();
};

std::ostream &	operator<<( std::ostream & o, Sorcerer const &wizard);

#endif