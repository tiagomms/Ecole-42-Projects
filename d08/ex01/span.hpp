// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Span.hpp                                           :+:      :+:
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

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <exception>

class Span {

public:
	Span(unsigned int N);
	Span(Span const & src);
	Span & operator=(Span const & src);
	~Span();

	void	addNumber(int nbr);
	int		shortestSpan();
	int		longestSpan();

	class	Overload : public std::exception
	{

	public:
		virtual const char * what() const throw();

		virtual ~Overload(void) throw(); //Canonical
		Overload(Overload const & src); //Canonical
		Overload & operator=(Overload const & src); //Canonical
		Overload();
	private:

	};

	class	InsufficientData : public std::exception
	{
	public:
		virtual const char * what() const throw();
		
		virtual ~InsufficientData() throw(); //Canonical
		InsufficientData(InsufficientData const & src); //Canonical
		InsufficientData & operator=(InsufficientData const & src); //Canonical
		InsufficientData(); //Canonical

	private:

	};	

private:
	Span(); //Canonical

	const unsigned int	_maxSize;
	std::list<int>		_list;
};

bool ascendent(int i, int j);

#endif