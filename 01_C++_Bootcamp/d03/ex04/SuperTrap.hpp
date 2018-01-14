// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   SuperTrap.hpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 10:15:47 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 10:15:48 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, FragTrap
{

public:
	SuperTrap(void); //Canonical
	~SuperTrap(void); //Canonical
	SuperTrap(SuperTrap const & src); //Canonical
	SuperTrap & operator=(SuperTrap const & src); // Canonical

	SuperTrap( std::string		name);
	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;
	using FragTrap::vaulthunter_dot_exe;
	using NinjaTrap::ninjaShoebox;
	
private:
	
};

#endif

/*
Hit points (Fragtrap)
• Max hit points (Fragtrap)
• Energy points (Ninjatrap)
• Max energy points (Ninjatrap)
• Level (1)
• Name (Parameter of constructor)
• Melee attack damage (Ninjatrap)
• Ranged attack damage (Fragtrap)
• Armor damage reduction (Fragtrap)
• rangedAttack (Fragtrap)
• meleeAttack (Ninjatrap)


// Teacher publicly inherits Person and Employee
class Teacher: public Person, public Employee
{
private:
     int m_nTeachesGrade;
 
public:
    Teacher(std::string strName, int nAge, bool bIsMale, std::string strEmployer, double dWage, int nTeachesGrade)
        : Person(strName, nAge, bIsMale), Employee(strEmployer, dWage), m_nTeachesGrade(nTeachesGrade)
    {
    }
};
*/