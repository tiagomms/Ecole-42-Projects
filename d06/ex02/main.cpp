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
//   Created: 2015/06/19 14:05:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <iostream>
#include <exception>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
	Base * result;
	int random = rand() % 3;

	if (random == 0)
		return result = new A;
	else if (random == 1)
		return result = new B;
	else
		return result = new C;
}

void identify_from_pointer( Base * p )
{
	A * a = dynamic_cast<A*>(p);
	B * b = dynamic_cast<B*>(p);
	C * c = dynamic_cast<C*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		//std::cout << a << std::endl;
	}
	else if (b)
	{
		std::cout << "B" << std::endl;
		//std::cout << b << std::endl;
	}
	else if (c)
	{
		std::cout << "C" << std::endl;
		//std::cout << c << std::endl;
	}
}

void identify_from_reference( Base & p )
{
	try 
	{
		A & a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		//std::cout << &a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "";
	}
	
	try 
	{
		B & b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		//std::cout << &b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "";
	}

	try 
	{
		C & c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		//std::cout << &c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "";
	}
}

int main()
{
	srand(time(NULL));

	std::cout << "BASE 1" << std::endl;
	
	Base * base = generate();
	//std::cout << "Base pointer: " << base << std::endl;
	std::cout << "identify_from_pointer - ";
	identify_from_pointer(base);

	std::cout << "identify_from_reference - ";
	identify_from_reference(*base);

	std::cout << std::endl << "BASE 2" << std::endl;

	Base * base2 = generate();
	//std::cout << "Base pointer: " << base2 << std::endl;
	std::cout << "identify_from_pointer - ";
	identify_from_pointer(base2);

	std::cout << "identify_from_reference - ";
	identify_from_reference(*base2);

	std::cout << std::endl << "BASE 3" << std::endl;

	Base * base3 = generate();
	//std::cout << "Base pointer: " << base3 << std::endl;
	std::cout << "identify_from_pointer - ";
	identify_from_pointer(base3);

	std::cout << "identify_from_reference - ";
	identify_from_reference(*base3);
}