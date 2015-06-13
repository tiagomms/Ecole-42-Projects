// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   solutions.cpp                                      :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/12 12:26:20 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/13 11:31:09 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"

//print Discriminant answer expected
static void	printDiscriminant(complex<double> discriminant)
{
	if (imag(sqrt(discriminant)) == 0)
	{
		if (discriminant != 0.0)
		{
			cout << "Discriminant is strictly positive ";
			if (is_integer(real(sqrt(discriminant))))
				cout << "with two REAL RATIONAL solutions, which are:" << endl;
			else
				cout << "with two REAL IRRATIONAL solutions, which are:" << endl;
		}
		else
		{
			cout << "Discriminant is ZERO, and therefore as only ONE REAL RATIONAL solution, which is:" << endl;
		}
	}
	else
		cout << "Discriminant is NEGATIVE with two COMPLEX solutions, which are:" << endl;
}

//print the solutions with immaginary and/or real components
static void printSolution(complex<double> solution)
{
	if (imag(solution) != 0.0)
	{
		if (ft_abs(real(solution)) > 1.0e-15)
			cout << real(solution) << " ";
		if (imag(solution) > 0.0)
			cout << "+ ";
		else
			cout << "- ";
		cout << ft_abs(imag(solution)) << "i";
	}
	else
		cout << (real(solution) == 0.0 ? 0 : real(solution));
}

//get and print final solutions, print discriminant
//and print irreducible fractions if possible
void	getSolutions(LinkedList &list1)
{
	complex<double> solution1;
	complex<double> solution2;
	double a;
	double b;
	double c;
	complex<double> discriminant;

	c = (list1.getCoef(0) != NULL ? list1.getCoef(0)->value : 0);
	b = (list1.getCoef(1) != NULL ? list1.getCoef(1)->value : 0);
	a = (list1.getCoef(2) != NULL ? list1.getCoef(2)->value : 0);
	if (list1.getDegree() == 1)
	{
		cout << "Equation is linear (and not quadratic) and the Solution is:" << endl;
		solution1 = - (c / b);
		printSolution(solution1);
		if (!is_integer(real(solution1)))
			printIrreducibleFractions_1stDegree(-c, b);
		cout << endl;
	}
	else if (list1.getDegree() == 2)
	{
		discriminant = (b * b) - (4 * a * c);
		solution1 = (-b - sqrt(discriminant)) / (2 * a);
		solution2 = (-b + sqrt(discriminant)) / (2 * a);
		printDiscriminant(discriminant);
		printSolution(solution1);
		if ((!is_integer(real(solution1)) && ft_abs(real(solution1)) > 1.0e-15) ||
			!is_integer(imag(solution1)))
			printIrreducibleFractions_2ndDegree(a, b, -sqrt(discriminant));
		cout << endl;
		if (real(discriminant) != 0.0 || imag(discriminant) != 0.0)
		{
			printSolution(solution2);
			if ((!is_integer(real(solution2)) && ft_abs(real(solution2)) > 1.0e-15) ||
				!is_integer(imag(solution2)))
				printIrreducibleFractions_2ndDegree(a, b, +sqrt(discriminant));
			cout << endl;
		}
	}
}
