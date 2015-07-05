// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   easyfind.hpp                                           :+:      :+:
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


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

template< typename T>
void	easyfind(T & container, int second)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), second);
	if (it != container.end())
		std::cout << second << " was found in the container" << std::endl;
	else
		throw std::exception();
}

#endif