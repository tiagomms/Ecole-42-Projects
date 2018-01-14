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

/*

Write a class template Array that contains elements of type T and that allows the
following behaviors:

• Construction with no parameter: creates an empty array.

• Construction with an unsigned int n as a parameter: creates an array of n elements,
initialized by default. (Tip: try to compile int * a = new int();, then
display *a.)

• Construction by copy and assignment operator. In both cases, modifying one of
the two arrays after copy/assignment won’t affect anything in the other array.

• You MUST use the operator new[] for your allocation. You must not do preventive
allocation. Your code must never access non allocated memory.

• Elements are accessible through the operator[].

• When accessing an element with the operator[], if this element is out of the limits,
a std::exception is thrown.

• A member function size that returns the number of elements in the array. This
member function takes no parameter and does not modify the current instance in
any way.

*/

#include "Array.tpp"

int main ()
{
	Array<int> array1;

	Array<int> array2(5);

	Array<int> array3(6);

	try
	{
		array1[2] = 5;
	}
	catch ( std::exception & e)
	{
		std::cout << e.what() << 2 << std::endl;
	}

	array2[0] = 0;
	array2[1] = 1;
	array2[2] = 2;
	array2[3] = 3;
	array2[4] = 4;

	array3[0] = 123;
	array3[1] = 123;
	array3[2] = 123;
	array3[3] = 123;
	array3[4] = 123;
	array3[5] = 123;



	int i = 0;
	while (i < 6)
	{
		try
		{
			std::cout << array1[i] << std::endl;
		}
		catch ( std::exception & e)
		{
			std::cout << e.what() <<  i << std::endl;
		}
		i++;
	}
	std::cout << std::endl;
	i = 0;
	while (i < 6)
	{
		try
		{
			std::cout << array2[i] << std::endl;
		}
		catch ( std::exception & e)
		{
			std::cout << e.what() << i << std::endl;
		}
		i++;
	}
	std::cout << std::endl;
	i = 0;
	while (i < 6)
	{
		try
		{
			std::cout << array3[i] << std::endl;
		}
		catch ( std::exception & e)
		{
			std::cout << e.what() << i << std::endl;
		}
		i++;
	}

	std::cout << std::endl;

	try
	{
		array2 = array3;
	}
	catch ( std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
}