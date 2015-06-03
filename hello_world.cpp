// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   hello_world.cpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/05/21 14:32:52 by tsilva            #+#
//   #+#             //
//   Updated: 2015/05/21 14:56:25 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //


//my first program in C++

#include <iostream>
using	namespace std; //so i don't write std::XXXXXX everytime I want
					   //do something in the standard library.
//using makes that it is no longer needed in this file to write the
//name in namespace.

int main(int argc, char **argv)
{
	if (argc >= 2)
		cout << argv[1]; //stuff to printed to stdout!
	cout << '\n';
	return (0);
}
