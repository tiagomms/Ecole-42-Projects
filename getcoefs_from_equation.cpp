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
//   Updated: 2015/06/05 21:43:31 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"

string	delete_spaces_from_equation(char *equation)
{
	const regex	space_pattern(" ");
	const char	*no_space;

	no_space = "";
	return regex_replace(equation, space_pattern, no_space);
}
/*
void	getCoefs_from_equation(string &equation, const char *error_string)
{
	string		start_pos;
	string 		integer;
	string 		real;
	string		times_x;
	string		just_x;
	string		exponential;
	string 		full_expression;	
	string		after_equal;
	string		before_equal;
	string		*copy_equation;

	start_pos = "(\\+|-|^)";
	integer = "[[:digit:]]+";
	real = "(" + start_pos + integer + "(\\." + integer + ")?)";
	times_x = "(\\*X)";
	just_x = "(" + start_pos + "X)";
	exponential = "\\^([\\+|\\-]?" + integer + ")";

	full_expression = "(" + real + "(" + times_x + "(" + exponential + ")" + "?" + ")" + "?" + ")" +
		"|" + "(" + just_x + "(" + exponential + ")" + "?" + ")";
	
	const regex full_expression_pattern(full_expression);

	copy_equation = new string;
	*copy_equation = equation;
	after_equal = copy_equation->erase(0, copy_equation->find_last_of("="));
	before_equal = equation.erase(equation.find_last_of("="),
								  equation.length() - equation.find_last_of("="));
	
	sregex_token_iterator coefs(before_equal.begin(), before_equal.end(), full_expression_pattern);
	const sregex_token_iterator end;
	while (coefs != end)
	{
		// object that will contain the sequence of sub-matches	
		cout << coefs->str() << endl;
		coefs++;

	}

}
*/

void	getCoefs_from_equation(string &equation, const char *error_string)
{
	string		start_pos;
	string 		integer;
	string 		real;
	string		times_x;
	string		just_x;
	string		exponential;
	string 		full_expression;	
	LinkedList 	*list1;
//	LinkedList 	*list2;
	string		after_equal;
	string		before_equal;
	string		*copy_equation;
	double		coef;
	int			degree;

	start_pos = "(\\+|-|^)";
	integer = "[[:digit:]]+";
	real = "(" + start_pos + integer + "(\\." + integer + ")?)";
	times_x = "(\\*X)";
	just_x = "(" + start_pos + "X)";
	exponential = "\\^([\\+|\\-]?" + integer + ")";

	full_expression = "(" + real + "(" + times_x + "(" + exponential + ")" + "?" + ")" + "?" + ")" +
		"|" + "(" + just_x + "(" + exponential + ")" + "?" + ")";
	
	const regex full_expression_pattern(full_expression);

	list1 = new LinkedList;
//	list2 = new LinkedList;

	copy_equation = new string;
	*copy_equation = equation;
	after_equal = copy_equation->erase(0, copy_equation->find_last_of("="));
	before_equal = equation.erase(equation.find_last_of("="),
								  equation.length() - equation.find_last_of("="));
	
	sregex_token_iterator coefs(before_equal.begin(), before_equal.end(), full_expression_pattern);
	const sregex_token_iterator end;
	const regex real_pattern(real);
	const regex times_x_pattern(times_x);
	const regex just_x_pattern(just_x);
	const regex exponential_pattern(exponential);
	cmatch result1;
	cmatch result2;
	cmatch result3;
	cmatch result4;
	while (coefs != end)
	{
		// object that will contain the sequence of sub-matches	
		
		cout << endl << coefs->str() << endl;

		if (regex_match(coefs->str().c_str(), result1, real_pattern))
			coef = atof((result1[0]).str().c_str());
		if (regex_match(coefs->str().c_str(), result2, times_x_pattern) ||
			regex_match(coefs->str().c_str(), result3, just_x_pattern))
		{
			degree = 1;
			if (regex_match(coefs->str().c_str(), result3, just_x_pattern))
				coef = ((result3[0]).str().c_str()[0] == '-' ? -1 : 1);
			//cout << result2[0] << endl;
			//cout << result3[0] << endl;
		}
		else
			degree = 0;
		if (regex_match(coefs->str().c_str(), result4, exponential_pattern))
			degree *= atoi((result4[0]).str().c_str());
		list1->insertCoef(new Coefficient(degree, coef));
		coefs++;
	}
	list1->printList();

		/*
		//3 capture groups defined within the parenthesis: (A) - value;
		//(X) - if X exists; (N) - key/degree, if it exists.
		//if (A && !X && !N) --> degree 0 [natural form], with value A
		//if (A && X && !N) --> degree 1 [natural form], with value A
		//if (A && X && N) --> degree N , with value A
		*/
}

int main(int argc, char **argv)
{
	string equation;
	
	if (argc >=2)
	{
		cout << argv[1] << endl;
		equation = delete_spaces_from_equation(argv[1]);
		cout << equation << endl << endl;		
		getCoefs_from_equation(equation, argv[1]);
	}
}


//"(\\^(\\+|-)?[[:digit:]]+)?)?)";
