// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   main.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:19:52 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:19:52 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"

int main()
{

	Logger A;
	std::string const info = "I've just farted";
	std::string const info2 = "Clumsy me";
	std::string const info3 = "Hope no one saw it";

	A.log("logToConsole", info);
	A.log("logToFile", info);
	A.log("logToConsole", info2);
	A.log("logToFile", info2);
	A.log("logToConsole", info3);
	A.log("logToFile", info3);		
	A.log("logToFart", info);
	return 0;
}