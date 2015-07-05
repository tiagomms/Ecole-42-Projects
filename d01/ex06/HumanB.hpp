// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   HumanB.hpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:18:21 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:18:22 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
Now, create two classes, HumanA and HumanB, that both have a Weapon, a name, and
an attack() function that displays something like :
NAME attacks with his WEAPON_TYPE
Make it so the following code produces attacks with "crude spiked club" THEN "some
other type of club", in both test cases :

*/

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
class HumanB {
	
public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &club);
	void attack( void );

private:
	const std::string _name;	
	Weapon * _weapon;
};

#endif