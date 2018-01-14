// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   EndLoop.cpp                                           :+:      :+:
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

#include "EndLoop.hpp"
#include "BeginLoop.hpp"


EndLoop::EndLoop() 
{
	return;
}

EndLoop::~EndLoop()
{
	return;
}

EndLoop::EndLoop(EndLoop const & src)
{
	*this = src;
	return;
}

EndLoop & EndLoop::operator=(EndLoop const & src)
{
	(void)src;
	return *this;
}

bool	EndLoop::execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it) //later
{
	in_parenthesis = (**p != 0);
	//std::cout << "in_parenthesis " << in_parenthesis << ", **it = " << **it << " , *(*it--) = " << *(*it - 1) << "\n";//
	if (in_parenthesis)//wrong
	{
		(*it)--;
		for (int nbr_parenthesis = 1 ; nbr_parenthesis != 0 ; (*it)--)
		{
			BeginLoop * beginLoop = dynamic_cast<BeginLoop*>(**it);
			EndLoop * endLoop = dynamic_cast<EndLoop*>(**it);			

			if (**it == endLoop)
			{
				nbr_parenthesis++;
			//	std::cout << "Got extra ]\n";
			}
			else if (**it == beginLoop)
			{
				nbr_parenthesis--;
			//	std::cout << "Got extra [\n";
			}
			if (!nbr_parenthesis)
				break;
		}
	}
	else
	{
		deque->pop_front();
		(*it) = deque->begin();
	}
	return in_parenthesis;
}
