// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ReadChar.cpp                                           :+:      :+:
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

#include "ReadChar.hpp"

ReadChar::ReadChar() 
{
	return;
}

ReadChar::~ReadChar()
{
	return;
}

ReadChar::ReadChar(ReadChar const & src)
{
	*this = src;
	return;
}

ReadChar & ReadChar::operator=(ReadChar const & src)
{
	(void)src;
	return *this;
}

bool	ReadChar::execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it) //later
{
	char c;
	std::cin >> c;
	**p = c;
	if (!in_parenthesis)
	{
		deque->pop_front();
		(*it) = deque->begin();
	}
	else
		(*it)++;
	return in_parenthesis;
}
