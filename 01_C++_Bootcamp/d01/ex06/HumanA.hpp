// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   HumanA.hpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:18:00 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:18:00 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
class HumanA {

public:	
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack( void );

private:
	const std::string _name;
	Weapon & _weapon;
};

#endif