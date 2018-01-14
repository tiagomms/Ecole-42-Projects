// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   printIrreducibleFractions.cpp                      :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/12 17:09:33 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/13 12:30:40 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "computorv1.hpp"

/*
 * printIrreducibleFractions 
 * Irredutible Fractions are printed if a,b and sqrt(discriminant)
 * [real or imaginary] are integers. They are obtained by greatest
 * common divisor (gcd).
 * The printing method for 1st degree or 2nd degree polynomials is
 * different, as seen below.
 *
 * Note: a,b,c are the real numbers in the polynomial equation:
 * a*x^2 + b*x + c = 0. 
*/

static int	gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

static bool	printFraction(int numerator, int denominator)
{
	if (numerator != 0 && denominator != 1)
	{
		if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator > 0))
			cout << "+ ";
		else
			cout << "- ";
		cout << "(" << ft_abs(numerator) << " / " << ft_abs(denominator) << ")";
		return true;
	}
	return false;
}

void		printIrreducibleFractions_1stDegree(double c, double b)
{
	int		gcd_result;
	int		c_int;
	int		b_int;
	
	if (is_integer(c) && is_integer(b))
	{
		c_int = c;
		b_int = b;
		gcd_result = gcd(ft_abs(c_int), ft_abs(b_int));
		c_int /= gcd_result;
		b_int /= gcd_result;
		cout << "\tor [ ";
		printFraction(c_int, b_int);
		cout << " ]";
	}
}

void		printIrreducibleFractions_2ndDegree(double a, double b,
									  complex<double> sqrt_discriminant)
{
	double	real_part;
	double	imag_part;
	int		gcd_result;
	int		gcd_result_complex;	
	int		numerator;
	int		numerator_complex;
	int		denominator;

	real_part = (ft_abs(real(sqrt_discriminant)) < 1.0e-15 ? 0 : real(sqrt_discriminant));
	imag_part = (ft_abs(imag(sqrt_discriminant)) < 1.0e-15 ? 0 : imag(sqrt_discriminant));
	denominator = 2 * a;
	numerator = -b + real_part;
	if (is_integer(b) && is_integer(denominator) && is_integer(real_part) &&
		(numerator != 0.0 || (imag_part != 0 && is_integer(imag_part))))
	{
		gcd_result = gcd(ft_abs(numerator), ft_abs(denominator));
		cout << "\tor [ ";
		if (printFraction(numerator / gcd_result, denominator / gcd_result))
			cout << " ";
		if (imag_part != 0)
		{
			if (is_integer(imag_part))
			{
				numerator_complex = imag_part;
				gcd_result_complex = gcd(ft_abs(numerator_complex), ft_abs(denominator));
				printFraction(numerator_complex / gcd_result_complex,
							  denominator / gcd_result_complex);
			}
			else
			{
				if ((imag_part / denominator) > 0.0)
					cout << "+ ";
				else
					cout << "- ";
				cout << ft_abs(imag_part / denominator);
			}
			cout << "i ";
		}
		cout << "]";
	}
}
