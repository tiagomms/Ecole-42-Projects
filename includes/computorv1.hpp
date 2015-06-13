// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   computorv1.hpp                                     :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/13 12:05:19 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/13 12:05:23 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _COMPUTORV1_HPP_
# define _COMPUTORV1_HPP_

#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <complex>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
 * absolute function for double, long long int, float and such
 */

template <class SomeType>
inline SomeType ft_abs(SomeType n)
{
	return (n < 0 ? -n : n);
}

template <class NbrType>
inline bool is_integer(NbrType k)
{
	return floor(k) == k;
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

	//set based on input what usages are being applied
	void set_usage(char *arg);

	//error for invalid usages
	void print_error(char  *arg) {
		cout << "Invalid usage:  " << arg << '\n';
		exit(1);
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
	Coefficient() : next(NULL) { }
	
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
	void insertCoef( Coefficient * newCoef , bool is2join_coefs);
	bool removeNullCoefs();

	//Overload operator functions
	LinkedList& operator -= (const LinkedList&);
	
	void printList();//to be removed
	
	//printing Equation Formula questions
	void printDegree();
	void printReducedForm(const Usages &);

	//final details to make equation valid for ComputorV1
	LinkedList&	endingJoiningLists(const LinkedList &, const Usages &);
	const LinkedList& sort_List();

	//Verify it is a valid equation to calculate
	Coefficient * lastCoef();	
	bool validComputorV();
};

string	delete_spaces_from_equation(char *equation);
void	getCoefs_from_equation(string &equation, LinkedList *list1,
							   LinkedList *list2);
void	getSolutions(LinkedList &list1);
void	printIrreducibleFractions_1stDegree(double c, double b);
void	printIrreducibleFractions_2ndDegree(double a, double b,
											complex<double> sqrt_discriminant);
#endif
