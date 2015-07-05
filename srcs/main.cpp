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
//   Created: 2015/06/04 15:15:08 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/30 16:52:16 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "computorv1.hpp"

void	do_computorv1(Usages &usage, char *equation_passed)
{
	string equation;
	LinkedList list1;
	LinkedList list2;

	//remove spaces and pass char * to string
	equation = delete_spaces_from_equation(equation_passed);

	//get coefficients in put them in list1 and list2, coefficients
	//before and after the "="
	getCoefs_from_equation(equation, &list1, &list2);

	// Match retrieved coefficients from both lists, and remove the
	// cases of value == 0
	list1 -= list2;
	list1.removeNullCoefs();
	list2.removeNullCoefs();

	//If a deterministic equation, end joining Lists, and remove the
	//null value cases.
	list1.endingJoiningLists(list2, usage);
	list1.removeNullCoefs();
	list2.removeNullCoefs();
	list1.sort_List();	

	//print Reduced Form and Degree
	list1.printReducedForm(usage);
	list1.printDegree();

	//is it valid? Get Solutions. Not can't solve
	if (list1.validComputorV())
		getSolutions(list1);
	else if (list1.getDegree() > 2)
		cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;
	else
		cout << "The polynomial equation has powers of X lower than 0, I can't solve." << endl;
}

int		main(int argc, char **argv)
{
	Usages	usage;
	int		i;
	string	has_equalsign;
	
	if (argc >= 2)
	{
		i = 1;
		while (argv[i] && i < argc - 1)
			usage.set_usage(argv[i++]);
		if (argv[i])
		{
			has_equalsign = string(argv[i]);
			if (has_equalsign.find('=') == string::npos)
				cerr << "Invalid equation: not = sign present" << endl;
			else
				do_computorv1(usage, argv[i]);
		}
	}
	else
		cerr << "Error - Equation not introduced" << endl; 
	return 0;
}
