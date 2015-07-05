// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Peon.hpp                                           :+:      :+:
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

#ifndef PEON_HPP
# define PEON_HPP

#include "Sorcerer.hpp"
#include "Victim.hpp"

class Peon : public Victim{

public:	
	virtual ~Peon(void); //Canonical
	Peon(Peon const & src); //Canonical
	Peon & operator=(Peon const & src); // Canonical

	Peon(std::string name);
	virtual void getPolymorphed() const;

private:
	Peon();
};

#endif