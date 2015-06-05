/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:25:32 by tsilva            #+#    #+#             */
/*   Updated: 2015/06/05 21:37:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMPUTORV1_H_
# define _COMPUTORV1_H_

#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>
#include <string.h>
#include <algorithm>//?
#include <vector>//?
using namespace std;

/*
 * absolute function for double, long long int, float and such
 */

template <class SomeType>
inline SomeType ft_abs(SomeType n)
{
	return (n < 0 ? -n : n);
}

/*
 * struct Usages is the holding public class for the bonuses made:
 * -n: natural display
 * -g: equation plot
 * -c: colors accordingly to the degree of each variable
 * -i: intermediate steps until the solving the polynomial equation
 * (fractions when seems interesting is a ninja bonus)
 *
 * set_usage: sets new usage (i.e. bonuses) and prints error if badly formatted
*/

struct Usages {
	static bool natural_display__n;
	static bool equation_graph__g;
	static bool degree_colors__c;
	static bool interm_steps__i;

	//set based on input what usages are being applied
	void set_usage(char *arg);

	//error for invalid usages
	void print_error(char  *arg) {
		cout << "Invalid usage:  " << arg << '\n';
		exit(1);
	}

	void print_usages() { //to be removed
		cout << "Usages activated:\n";
		cout << "-n: " << natural_display__n << '\n';
		cout << "-g: " << equation_graph__g << '\n';
		cout << "-c: " << degree_colors__c << '\n';
		cout << "-i: " << interm_steps__i << '\n';		
		cout << '\n';
	}
};


/*
 * Coefficient - holds the coefficient value (value --> double)
 * and its degree, which acts as key (key --> int), of the polynomial values
 * written in ComputorV1 string, and a next Coefficient (*next)
*/

struct	Coefficient {

	//polynomial degree, which is my key
	int				key;

	//coefficient value
	double			value;
	
	Coefficient *	next;

	//Original constructor
	Coefficient() {}
	
	//overload constructor in case I have a value and key to store
	Coefficient(int x, double y) : key(x) , value(y), next(NULL) { } 

	//Operations with coeficients
	const Coefficient& operator += (const Coefficient&);
	const Coefficient& operator -= (const Coefficient&);
	const Coefficient& operator = (const Coefficient&);

	//functions for sorting function
	void coefSwap(Coefficient *);

	//printing Coefficient functions
	void printCoefficient(const Usages&);
};


/*
 * Linked lists store a variable number of Coefficients. It holds also
 * its length (length) and the equation's polynomial degree.
*/

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

	//destructor
	~LinkedList();

	//get private variables functions
	int getLength();
	int getDegree();
	Coefficient * getCoef( int coefDegree );

	//insert , remove Coefficients
	void insertCoef( Coefficient * newCoef );
	bool removeNullCoefs();

	//Overload operator functions
	LinkedList& operator -= (const LinkedList&);
	
	void printList();//to be removed
	
	//printing Equation Formula questions
	void printDegree();
	void printReducedForm(const Usages &);

	//functions to validate ComputerV1
	LinkedList&	endingJoiningLists(const LinkedList &);
	const LinkedList& sort_List();

	//Verify it is a valid equation to calculate
	Coefficient * lastCoef();	
	bool validComputorV();
};

#endif
