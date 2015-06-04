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
//   Updated: 2015/06/04 18:48:59 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"


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
	if (value != 0)
	{
		cout << ft_abs<double>(value);
		if (usage.natural_display__n)
		{
			cout << (key == 0 ? "" : " * X");
			if (key > 1)
				cout << "^" << key;
		}
		else
		{
			cout << " * X^" << key;
		}
	}
}
