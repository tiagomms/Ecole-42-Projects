// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Human.cpp                                          :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:19:16 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:19:16 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack on " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout to " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	int choosen_action_pos;
	void (Human::*function_Array[3])(std::string const &) = {NULL};
	function_Array[0] = &Human::meleeAttack;
	function_Array[1] = &Human::rangedAttack;
	function_Array[2] = &Human::intimidatingShout;
	std::string	actions[3] = { "meleeAttack", "rangedAttack", "intimidatingShout" };

	choosen_action_pos = 0;
	while (choosen_action_pos < 3)
	{
		if (action_name == actions[choosen_action_pos])
			return (this->*function_Array[choosen_action_pos])(target);
		choosen_action_pos++;
	}
	std::cout << "ERROR - UNDEFINED ACTION: " << action_name << " to... " 
	<< target << std::endl;
}
