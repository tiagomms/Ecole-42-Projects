// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   coef_classes.cpp                                   :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/05/31 18:03:13 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/03 21:31:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "coefficient.h"

/*
 * code adapted from:
 *    http://pumpkinprogrammer.com/2014/06/21/c-tutorial-intro-to-hash-tables/
 * 
 * LinkedList is created to find the coefficient value for any polinomial 
 * degree (N in X^N) in Computor V1, it will hold the key --> N value
 * and the coefficient --> double.
 *
*/

//overload operator to only add value, and not key
const Coefficient& Coefficient::operator+= (const Coefficient& second_coef) {
	value += second_coef.value;
	return *this;
}

//overload operator to only minus value, and not key
const Coefficient& Coefficient::operator-= (const Coefficient& second_coef) {
	value -= second_coef.value;
	return *this;
}

//overload operator to equal two coefficients
const Coefficient& Coefficient::operator= (const Coefficient& second_coef) {
	key = second_coef.key;
	value = second_coef.value;
	return *this;
}

//swap values between this coefficient and a given second one
void Coefficient::coefSwap(Coefficient * second)
{
	Coefficient *temp;

	temp = new Coefficient;
	*temp = *this;
	*this = *second;
	*second = *temp;
	delete temp;
}

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
	head = new Coefficient;
	length = 0;
	degree = 0;
}

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

//removes a coefficient based on its key
//returns true if successful
bool LinkedList::removeCoef( int coefDegree )
{
	Coefficient * p;
	Coefficient * q;

	if (!head) return false;
	p = head;
	q = head;
	while (q)
	{
		if (q -> key == coefDegree)
		{
			p -> next = q -> next;
			delete q;
			length--;
			return true;
		}
		p = q;
		q = p -> next;
	}
	return false;
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

inline void LinkedList::printDegree()
{
	cout << "Polynomial Degree: " << getDegree() << endl;	
}

// overload operator to subtract two lists, which in this case it will
// insert new coefficients or change, if both coefficients have the
// same key
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

//return true if keys are in ascending order
inline bool ascending_order (Coefficient *first, Coefficient *second)
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

void	Coefficient::printNaturalForm()
{
	cout << ft_abs<double>(value);
	cout << (key == 0 ? "" : " * X");
	if (key > 1)
		cout << "^" << key;
}

void	LinkedList::printReducedForm()
{
	Coefficient *p;

	p = head->next;
	cout << "Reduced Form: ";
	if (p->value < 0)
		cout << "-";
	p->printNaturalForm();
	p = p->next;
	while (p)
	{
		if (p->value < 0)
			cout << " - ";
		else
			cout << " + ";
		p->printNaturalForm();
		p = p->next;
	}
	cout << " = 0\n";
}

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
// End of Linked Lists
//*****************************************************************

int main()
{
	// Create 8 Coefficients to store in the Linked Lists.
	Coefficient * A = new Coefficient(6, 2.5);
	Coefficient * B = new Coefficient(3, 1);
	Coefficient * C = new Coefficient(0, 1);
	Coefficient * D = new Coefficient(4, 3);
	Coefficient * E = new Coefficient(2, 2.5);
	Coefficient * F = new Coefficient(1, 19);
	Coefficient * G = new Coefficient(5, 3);
	Coefficient * H = new Coefficient(7, 1);
	// Create a Linked List.
	LinkedList list;
	LinkedList list2;

	// Add 4 Items to Hash Table, getLength and Print them.
 	list.insertCoef(A);
	list.insertCoef(B);
	list.insertCoef(C);
	list.insertCoef(D);

	// Add the other 4 items to Hash Table, and verify if overloading works.
 	list2.insertCoef(E);
	list2.insertCoef(F);
	list2.insertCoef(G);
	list2.insertCoef(H);
/*
	printf("InitialList - Length: %d\n", list.getLength());
	list.printList();
	
	printf("\nInitialList2 - Length: %d\n", list2.getLength());
	list2.printList();
*/
	list -= list2;
/*
	printf("\n\nUpdatedList - Length: %d\n", list.getLength());
	list.printList();
	printf("\nUpdatedList2 - Length: %d\n", list2.getLength());
	list2.printList();
*/	
	list.removeNullCoefs();
	list2.removeNullCoefs();
/*
	printf("\n\nRemoved stuff List - Length: %d\n", list.getLength());
	list.printList();
	printf("\nRemoved stuff List2 - Length: %d\n", list2.getLength());
	list2.printList();
*/
	list.endingJoiningLists(list2);
	list.removeNullCoefs();
	list2.removeNullCoefs();
	list.sort_List();	
/*	
	printf("\n\nSort List - Length: %d\n", list.getLength());
	list.printList();
	printf("\nRemoved stuff List2 - Length: %d\n", list2.getLength());
	list2.printList();

	printf("\nRESULT --------------------\n");
*/	
	list.printReducedForm();
	list.printDegree();

	printf(list.validComputorV() ? "true\n" : "Invalid polynomial\n");
	return 0;
}
