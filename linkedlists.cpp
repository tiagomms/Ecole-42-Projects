// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   linkedlists.cpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/04 15:12:13 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/11 17:19:46 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"

/*
 * code adapted from:
 *    http://pumpkinprogrammer.com/2014/06/21/c-tutorial-intro-to-hash-tables/
*/

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
	head = new Coefficient;
	length = 0;
	degree = 0;
}


// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
	Coefficient * p;
	Coefficient * q;

	p = head;
	q = head;
	while (q)
	{
		p = q;
		q = p -> next;
		if (q) delete p;
	}
}


//*****************************************************************
// Get private variables functions
//*****************************************************************

// Returns the length of the list.
inline int LinkedList::getLength()
{
	return length;
}

// Returns the Degree of the list.
inline int LinkedList::getDegree()
{
	return degree;
}

// Searches for a coefficient by its key (polynomial degree).
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Coefficient * LinkedList::getCoef( int coefDegree )
{
	Coefficient * p = head;
	Coefficient * q = head;
	while (q)
	{
		p = q;
		if ((p != head) && (p -> key == coefDegree))
			return p;
		q = p -> next;
	}
	return NULL;
}


//*****************************************************************
// Insert, Remove Coefficients
//*****************************************************************

// Inserts an Coefficient at the end of the list. If
// coefficients have the same key, they are added to each other
void LinkedList::insertCoef( Coefficient * newCoef )
{
	Coefficient * p;
	Coefficient * q;
	Coefficient * cloneCoef;

	if (!newCoef)
		return ;
	cloneCoef = new Coefficient;
	*cloneCoef = *newCoef;
	cloneCoef -> next = NULL;
	if (!head -> next)
	{
		head -> next = cloneCoef;
		length++;
		return;
	}
	p = head;
	q = head;
	while (q)
	{
		p = q;
		if ((p != head) && (newCoef -> key == p -> key))
		{
			*p += *newCoef;
			return;
		}
		q = p -> next;
	}
	p -> next = cloneCoef;
	length++;
}

// Removes a coefficient from the list which value is null.
// Return 1 if the operation is successful.
bool LinkedList::removeNullCoefs()
{
	Coefficient * p;
	Coefficient * q;

	if (!head) return false;
	p = head;
	q = head;
	while (q)
	{
		if (q != head && q-> value == 0.0)
		{
			p -> next = q -> next;
			delete q;
			q = p;
			length--;
		}
		else
		{
			p = q;
			q = p -> next;
		}
	}
	return true;
}

//*****************************************************************
// Overload Operator Functions
//*****************************************************************

// overload operator to subtract two lists. It will insert new
//coefficients or change, if both coefficients have the same key
LinkedList& LinkedList::operator -= (const LinkedList& secondList)
{
	Coefficient * p;

	p = secondList.head;
	while (p)
	{
		if (p != head && p->key != 0)
		{
			p->value *= -1;
			this->insertCoef(p);
			p->value = 0;
		}
		p = p->next;
	}
	return *this;
}


//  REMOVE
	
// Displays list contents to the console window.
void LinkedList::printList()
{
	Coefficient * p;
	Coefficient * q;

	if (length == 0)
	{
		cout << "n{ }n";
		cout << "\n";	
		return;
	}
	p = head;
	q = head;
	cout << "n{ ";
	while (q)
	{
		p = q;
		if (p != head)
		{
			cout << p -> key;
			cout << " - ";
			cout << p -> value;
			if (p -> next) cout << ", ";
			else cout << " ";
		}
		q = p -> next;
	}
	cout << "}n";
	cout << "\n";
}


//*****************************************************************
// Printing Equation Formula Eqautions
//*****************************************************************

//print the Degree as written in the subject
inline void LinkedList::printDegree()
{
	cout << "Polynomial Degree: " << getDegree() << endl;	
}

//print Reduced Form Equation
void	LinkedList::printReducedForm(const Usages& usage)
{
	Coefficient *p;

	p = head->next;
	cout << "Reduced Form: ";
	if (p->value < 0)
		cout << "-";
	p->printCoefficient(usage);
	p = p->next;
	while (p)
	{
		if (p->value < 0)
			cout << " - ";
		else
			cout << " + ";
		p->printCoefficient(usage);
		p = p->next;
	}
	cout << " = 0\n";
}

//*****************************************************************
// Functions to validate computorV1.
//*****************************************************************

//return true if keys are in ascending order
inline bool ascending_order(Coefficient *first, Coefficient *second)
{
	return (first->key <= second->key);
}

//algorithm used to sort the list in descending order.
//returns the LinkedList
const LinkedList& LinkedList::sort_List()
{
	Coefficient **	first;
	Coefficient *	lst;
	bool			changed;

	first = &head;
	if ((*first) -> next)
	{
		changed = true;
		while (changed)
		{
			changed = false;
			lst = *first;
			while (lst->next)
			{
				if (ascending_order(lst, lst->next) && lst != head)
				{
					lst->coefSwap(lst->next);
					changed = true;
				}
				lst = lst->next;
			}
		}
		degree = (*first)->next->key;
	}
	return *this;
}

LinkedList&	LinkedList::endingJoiningLists(const LinkedList &secondList)
{
	Coefficient *lst1;
	Coefficient *lst2;
	double		value1;
	double		value2;	

	lst1 = head->next;
	lst2 = (secondList.head)->next;
	if (((length == 1 && lst1->key == 0) || !lst1) &&
		(!lst2 || secondList.length == 1))
	{
		value1 = (!lst1 ? 0 : lst1->value);
		value2 = (!lst2 ? 0 : lst2->value);
		cout << "Reduced Form: " << value1 << " = " << value2 << endl;
		printDegree();
		if (value1 == value2)
			cout << "All real numbers are solution\n";
		else
			cout << "Impossible to Solve\n" ;
		exit(0);
	}
	if (lst2)
	{
		lst2->value *= -1;
		this->insertCoef(lst2);
		lst2->value = 0;
	}
	return *this;
}


//*****************************************************************
// Verify it is a valid equation to calculate
//*****************************************************************

//return lastCoef from the LinkedList
Coefficient * LinkedList::lastCoef()
{
	Coefficient * p;

	p = head;
	while (p->next)
		p = p->next;
	return p;
}

//evaluates if it is a valid algorithm for ComputerV1
bool	LinkedList::validComputorV()
{
	Coefficient * p;

	p = head;
	return (length > 0 && degree <= 2 && (this->lastCoef())->key >= 0);
}

//*****************************************************************
// End of Linked Lists
//*****************************************************************
