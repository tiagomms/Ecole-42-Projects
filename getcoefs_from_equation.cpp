// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   getcoefs_from_equation.cpp                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/04 18:55:40 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/13 11:26:13 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"
#include <stdio.h>

// replace spaces for nothing in the equation
string	delete_spaces_from_equation(char *equation)
{
	const regex	space_pattern(" ");
	const char	*no_space;

	no_space = "";
	return regex_replace(equation, space_pattern, no_space);
}

/*
 * goal: divide 2 parts of the equation in 2 Lists of coefficients.
 * To do it I use regex written below, to collect the Coefficients
 * Coefficients can be written in two ways:
 * 	-> a (* X(^N)?)?, a is real
 *  -> X(^N)?, N is integer
 *
 * strtok divides the equation in 2 parts, with the delimiter "="
 * sregex_token_iterator is used to get all coefficients (that respected the
 * pattern). Then regex_search is used to find each part individually:
 * key and value
*/

void	getCoefs_from_equation(string &equation, LinkedList *list1, LinkedList *list2)
{
	string		start_pos;
	string 		integer;
	string 		real;
	string		times_x;
	string		just_x;
	string		exponential;
	string 		full_expression;
	double		coef;
	int			degree;
	char		*copy_equation;
	char		*part_of_equation;
	string		before_equal;
	string		after_equal;

	//Set up of the regex:
	start_pos = "(\\+|-|^)";
	integer = "[[:digit:]]+";
	real = "(" + start_pos + integer + "(\\." + integer + ")?)";
	times_x = "\\*(X)";
	just_x = "(" + start_pos + "X)";
	exponential = "\\^([\\+|-]?" + integer + ")";
	full_expression = "(" + real + "(" + times_x + "(" + exponential + ")" + "?" + ")" + "?" + ")"
		+ "|" + "(" + just_x + "(" + exponential + ")" + "?" + ")";

	const regex real_pattern(real);
	const regex times_x_pattern(times_x);
	const regex just_x_pattern(just_x);
	const regex exponential_pattern(exponential);
	const regex full_expression_pattern(full_expression);
	cmatch match_real;
	cmatch match_times_x;
	cmatch match_just_x;
	cmatch match_exponential;

	copy_equation = new char[equation.length() + 1];
	strcpy(copy_equation, equation.c_str());

	//coefs for the part of the string before the equal
	part_of_equation = strtok(copy_equation, "=");
	before_equal = string(part_of_equation);
	sregex_token_iterator coefs(before_equal.begin(), before_equal.end(), full_expression_pattern);
	const sregex_token_iterator end;
	
	while (coefs != end)
	{
		if (regex_search(coefs->str().c_str(), match_real, real_pattern))
			coef = atof((match_real[0]).str().c_str());
		if (regex_search(coefs->str().c_str(), match_times_x, times_x_pattern))
			degree = 1;
		else if (regex_search(coefs->str().c_str(), match_just_x, just_x_pattern))
		{
			degree = 1;
			coef = ((match_just_x[0]).str().c_str()[0] == '-' ? -1 : 1);
		}
		else
			degree = 0;
		if (regex_search(coefs->str().c_str(), match_exponential, exponential_pattern))
			degree *= atoi((match_exponential[1]).str().c_str());
		list1->insertCoef(new Coefficient(degree, coef), true);
		coefs++;
	}

	//coefs for the part of the string after the equal
	part_of_equation = strtok(NULL, "=");
	after_equal = string(part_of_equation);
	sregex_token_iterator coefs2(after_equal.begin(), after_equal.end(), full_expression_pattern);
	
	while (coefs2 != end)
	{
		if (regex_search(coefs2->str().c_str(), match_real, real_pattern))
			coef = atof((match_real[0]).str().c_str());
		if (regex_search(coefs2->str().c_str(), match_times_x, times_x_pattern))
			degree = 1;
		else if (regex_search(coefs2->str().c_str(), match_just_x, just_x_pattern))
		{
			degree = 1;
			coef = ((match_just_x[0]).str().c_str()[0] == '-' ? -1 : 1);
		}
		else
			degree = 0;
		if (regex_search(coefs2->str().c_str(), match_exponential, exponential_pattern))
			degree *= atoi((match_exponential[1]).str().c_str());
		list2->insertCoef(new Coefficient(degree, coef), true);
		coefs2++;
	}	
	if (part_of_equation)
		part_of_equation = strtok(NULL, "=");
	delete[] copy_equation;
}
