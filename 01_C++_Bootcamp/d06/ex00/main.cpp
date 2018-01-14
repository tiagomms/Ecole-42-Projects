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
//   Created: 2015/06/19 14:05:44 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Converter.hpp"

/*

Write a program that takes a string representation of a C++ literal value (in its most
common form) as a parameter. This literal MUST belong to one of the following a scalar
types: char, int, float or double. Only the decimal notation will be used.

Examples of char literal values: ’c’, ’a’, ... To simplify, please note that : non displayable
characters can’t be passed as a parameter to your program, and if a conversion
to char is not displayable, output a notification instead.

Examples of int literal values: 0, -42, 42, ...

Examples of float literal values: 0.0f, -4.2f, 4.2f, ... You will also accept these
pseudo literals as well, you know, for science: -inff, +inff and nanf.

Examples of double literal values: 0.0, -4.2, 4.2, ... You will also accept these
pseudo literals as well, you know, for... fun: -inf, +inf and nan.

Your program must detect the literal’s type, acquire that literal in the right type (so
it’s not a string anymore), then convert it EXPLICITLY to each of the three other types and
display the results using the same formatting as below. If a conversion does not make
sense or overflows, display that the conversion is impossible. You can include any header
you need to handle numeric limits and special values.


$>./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

$>./convert nan
char: impossible
int: impossible
float: nanf
double: nan

$>./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0



*/

//using dynamic casts with cast operators and explicits

//need this - header you need to handle numeric limits and special values


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::cout.precision(1);
		Converter converter;
		std::string literal = std::string(argv[1]);
		converter.printResults(literal);
	}
	else
		std::cout << std::endl;
}