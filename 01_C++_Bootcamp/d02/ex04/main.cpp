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
//   Created: 2015/06/17 20:57:28 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/17 20:57:29 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.class.hpp"

#include <string>
#include <sstream>
#include <fstream>

Fixed &	eval_things(std::string total_string, Fixed &result)
{
	std::istringstream	stream(total_string);
	size_t 				i;
	float 				value;
	std::string			rest_string;

	i = 0;
	stream >> value;
	stream >> rest_string;
	Fixed				obtained_value(value);
	while (i < total_string.length())
	{
		if (total_string[i] == ')')
			return result;
		else if (total_string[i] == '(')
			return eval_things(rest_string, obtained_value);
		else if (total_string[i] == '*')
			result = result * obtained_value;
		else if (total_string[i] == '/')
			result = result / obtained_value;
		else if (total_string[i] == '+')
			result = result + obtained_value;
		else if (total_string[i] == '-')
			result = result + obtained_value;
		i++;
	}
	return result;
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid arguments\n";
		return 0;
	}
	std::ifstream	in(argv[1]);
	std::string line;
	std::getline(in, line);
	Fixed result;
	result = eval_things(line, result);
	std::cout << result.toFloat() << std::endl;
	in.close();
	return 0;
}