// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   coefficients.cpp                                   :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/04 15:12:01 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/13 11:06:08 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.hpp"

//overload operator to only add value, and not key
const Coefficient& Coefficient::operator+= (const Coefficient& second_coef) {
	value += second_coef.value;
	return *this;
}

//overload operator to only minus value, and not key
const Coefficient& Coefficient::operator-= (const Coefficient& second_coef) {
	value -= second_coef.value;
	return *this;
}

//overload operator to equal two coefficients
const Coefficient& Coefficient::operator= (const Coefficient& second_coef) {
	key = second_coef.key;
	value = second_coef.value;
	return *this;
}

//swap values between this coefficient and a given second one
void Coefficient::coefSwap(Coefficient * second)
{
	Coefficient *temp;

	temp = new Coefficient;
	*temp = *this;
	*this = *second;
	*second = *temp;
	delete temp;
}

//print Coefficient in natural form (bonus) if -n activated or in the
//subject form otherwise
void	Coefficient::printCoefficient(const Usages& usage)
{
	if (value != 0 || key == 0)
	{
		if (usage.natural_display__n)
		{
			if (ft_abs<double>(value) != 1 || key == 0)
				cout << ft_abs<double>(value);
			if (ft_abs<double>(value) != 1 && key != 0)
				cout << " * X";
			else if (ft_abs<double>(value) == 1 && key != 0)
				cout << "X";
			if (key > 1 || key <= -1)
				cout << "^" << key;
		}
		else
		{
			cout << ft_abs<double>(value);
			cout << " * X^" << key;
		}
	}
}
