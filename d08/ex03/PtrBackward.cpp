// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PtrBackward.cpp                                           :+:      :+:
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

#include "PtrBackward.hpp"

PtrBackward::PtrBackward() 
{
	return;
}

PtrBackward::~PtrBackward()
{
	return;
}

PtrBackward::PtrBackward(PtrBackward const & src)
{
	*this = src;
	return;
}

PtrBackward & PtrBackward::operator=(PtrBackward const & src)
{
	(void)src;
	return *this;
}

bool	PtrBackward::execute(bool in_parenthesis, char** p,
	std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it)
{
	(*p)--;
	if (!in_parenthesis)
	{
		deque->pop_front();
		(*it) = deque->begin();
	}
	else
		(*it)++;
	return in_parenthesis;
}