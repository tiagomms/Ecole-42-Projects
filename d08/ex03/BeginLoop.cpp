// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   BeginLoop.cpp                                           :+:      :+:
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

#include "BeginLoop.hpp"
#include "EndLoop.hpp"

BeginLoop::BeginLoop() 
{
	return;
}

BeginLoop::~BeginLoop()
{
	return;
}

BeginLoop::BeginLoop(BeginLoop const & src)
{
	*this = src;
	return;
}

BeginLoop & BeginLoop::operator=(BeginLoop const & src)
{
	(void)src;
	return *this;
}

bool	BeginLoop::execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it)
{
	in_parenthesis = (**p != 0);
	//std::cout << "in_parenthesis: " << in_parenthesis << " , **p = " << (int)**p << "\n";//
	if (!in_parenthesis)
	{
		deque->pop_front();
		for (int nbr_parenthesis = 1 ; nbr_parenthesis != 0 ; deque->pop_front())
		{
			(*it) = deque->begin();
			//std::cout << "BeginLoop stuck\n";//
			BeginLoop * beginLoop = dynamic_cast<BeginLoop*>(**it);
			EndLoop * endLoop = dynamic_cast<EndLoop*>(**it);			
			if (**it == beginLoop)
				nbr_parenthesis++;
			else if (**it == endLoop)
				nbr_parenthesis--;
			if (!nbr_parenthesis)
				break;
		}
		(*it) = deque->begin();
	}
	else
	{
		(*it)++;
	}
	return in_parenthesis;
}
