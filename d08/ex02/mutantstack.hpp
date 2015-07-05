// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   MutantStack.hpp                                           :+:      :+:
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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	typedef T *iterator;

	MutantStack<T>() { return; } //Canonical
	
	MutantStack<T>(MutantStack<T> const & src)
	{
	*this = src;
	return;
	}

	MutantStack<T> & operator=(MutantStack<T> const & src)
	{
		(void)src;
		return *this;
	}

	virtual ~MutantStack<T>() { return; }

	iterator begin()
	{
		iterator element = &(this->top()) - this->size() + 1;
		return element;
	}

	iterator end()
	{
		iterator end = &(this->top()) + 1;
		return end;
	}

private:

	
};

#endif