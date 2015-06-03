/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coefficient.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:03:00 by tsilva            #+#    #+#             */
/*   Updated: 2015/06/03 21:29:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COEFFICIENT_H_
# define _COEFFICIENT_H_

/*
 * Structure of all coefficients of X^N power - linkedlists with:
 * degree, value.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <class SomeType>
inline SomeType ft_abs(SomeType n)
{
	return (n < 0 ? -n : n);
}

//*****************************************************************
// List items are keys with pointers to the next item.
//*****************************************************************

struct	Coefficient {

	//polynomial degree, which is my key
	int				key;

	//coefficient value
	double			value;
	
	Coefficient *	next;

	//Original constructor
	Coefficient() {}
	//Overloading constructor
	Coefficient(int x, double y) : key(x) , value(y), next(NULL) { } 
													 
	//Operations with coeficients
	const Coefficient& operator += (const Coefficient&);
	const Coefficient& operator -= (const Coefficient&);
	const Coefficient& operator = (const Coefficient&);

	//functions for sorting function
	void coefSwap(Coefficient *);

	void printNaturalForm();
};

//*****************************************************************
// Linked lists store a variable number of items.
//*****************************************************************
class LinkedList
{
private:
	
	// Head is a reference to a list of data nodes.
	Coefficient *	head;

	// Length is the number of data nodes.
	int				length;

	// explanations in file.
	int				degree;
	
public:
	//constructor
	LinkedList();

	void insertCoef( Coefficient * newCoef );
	bool removeCoef( int coefDegree );//not needed
	Coefficient * getCoef( int coefDegree );
	bool removeNullCoefs();
	int getLength();
	int getDegree();	

	//to be removed
	void printList();

	void printDegree();
	void printReducedForm();
	
	//operations with coefficients
	LinkedList& operator -= (const LinkedList&);
	const LinkedList& sort_List();

	LinkedList&	endingJoiningLists(const LinkedList &);

	Coefficient * lastCoef();	
	bool validComputorV();


	//destructor
	~LinkedList();
};

#endif
