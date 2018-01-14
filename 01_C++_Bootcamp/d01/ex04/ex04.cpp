// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ex04.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:05:40 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:05:41 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main (void)
{
	std::string 	str = "HI THIS IS BRAIN";
	std::string *	str_ptr = &str;
	std::string &	str_ref = str;

	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;	
}
