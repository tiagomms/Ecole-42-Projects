// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   span.cpp                                           :+:      :+:
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

#include "span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{
}

void Span::addNumber(int nbr)
{
	if (this->_list.size() < this->_maxSize)
		this->_list.push_back(nbr);
	else
		throw Span::Overload();
}


bool ascendent(int i, int j)
{
	return i <= j;
}

int Span::shortestSpan()
{
	int shortestSpan;
	int temp;

	if (this->_list.size() >= 2)
	{
		std::list<int> copy = this->_list;
		copy.sort(ascendent);
		std::list<int>::iterator ite = copy.end();
		std::list<int>::iterator it = copy.begin();
		ite--;
		shortestSpan = (*ite - *it);
		temp = *it;
		ite++;
		while (++it != ite)
		{
			if ((*it - temp) < shortestSpan)
				shortestSpan = (*it - temp);
			if (!shortestSpan)
				break;
			temp = *it;
		}
	}
	else
		throw Span::InsufficientData();
	return shortestSpan;
}

int Span::longestSpan()
{
	int longestSpan;

	if (this->_list.size() >= 2)
	{
		std::list<int> copy = this->_list;

		copy.sort(ascendent);
		std::list<int>::iterator ite = copy.end();
		ite--;
		std::list<int>::const_iterator it = copy.begin();
		longestSpan = (*ite - *it);
	}
	else
		throw Span::InsufficientData();
	return longestSpan;
}


const char * Span::InsufficientData::what() const throw()
{
	return "ERROR: To run, it is required two or items in list.";
}

const char * Span::Overload::what() const throw()
{
	return "ERROR: Impossible to addNumber, over the pre-established N";
}

Span::Span() : _maxSize(0) { return; }

Span::Span(Span const & src) : _maxSize(src._maxSize)
{
	*this = src;
	return;
}

Span & Span::operator=(Span const & src)
{
	this->_list = src._list;
	return *this;
}

Span::~Span()
{
	return;
}


Span::InsufficientData::~InsufficientData(void) throw()
{
	return;
}

Span::InsufficientData::InsufficientData(InsufficientData const & src)
{
	*this = src;
	return;
}

Span::InsufficientData & Span::InsufficientData::operator=(InsufficientData const & src)
{
	*this = src;
	return *this;
}

Span::InsufficientData::InsufficientData()
{
	return;
}


Span::Overload::~Overload(void) throw()
{
	return;
}

Span::Overload::Overload(Overload const & src)
{
	*this = src;
	return;
}

Span::Overload & Span::Overload::operator=(Overload const & src)
{
	*this = src;
	return *this;
}

Span::Overload::Overload()
{
	return;
}
