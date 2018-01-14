// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   iter.cpp                                           :+:      :+:
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

#include <iostream>

template< typename T >
void	iter(T ** array, int size, void (*function)(T & element))
{
	int i = 0;

	while (i < size)
	{
		(*function)((*array)[i]);
		i++;
	}
}


void	multiply_2(int & value)
{
	value = 2 * value;
}

void	printString(std::string & string)
{
	std::cout << string << std::endl;
}

int main(void) {

	int size = 5;
	int i = 0;
	int * array = new int[size];
	std::string * str = new std::string[size];

	str[0] = "Hello";
	str[1] = "random";
	str[2] = "correcteur";	
	str[3] = "Please";
	str[4] = "correctais.";

	std::cout << "Values Before iter INT CASE" << std::endl;
	while (i < size)
	{
		array[i] = i;
		std::cout << "array[ " << i << " ] = " << array[i] << std::endl;
		i++;
	}
	iter(&array, size, &multiply_2);
	i = 0;
	std::cout << std::endl << "Values After iter INT CASE" << std::endl;		
	while (i < size)
	{
		std::cout << "array[ " << i << " ] = " << array[i] << std::endl;
		i++;
	}

	std::cout << std::endl << "Iter - STRING CASE" << std::endl;
	iter(&str, size, &printString);
	return 0;
}

