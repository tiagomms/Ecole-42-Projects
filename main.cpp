// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   main.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/04 15:15:08 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/11 10:46:14 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"

int main(int argc, char **argv)
{
	Usages	usage;
	int		i;
	
	if (argc >= 2)
	{
		i = 1;
		while (argv[i] && i < argc - 1)
			usage.set_usage(argv[i++]);
		usage.print_usages();//to be removed	
		if (argv[i])
		{
			cout << argv[i]; //stuff to printed to stdout!
			cout << '\n';
		}
	}
	
	// Create 8 Coefficients to store in the Linked Lists.
	Coefficient * A = new Coefficient(6, 2.5);
	Coefficient * B = new Coefficient(2, 1);
	Coefficient * C = new Coefficient(0, 1);
	Coefficient * D = new Coefficient(1, 3);
	Coefficient * E = new Coefficient(6, 2.5);
	Coefficient * F = new Coefficient(1, 19);
	Coefficient * G = new Coefficient(2, 3);
	Coefficient * H = new Coefficient(0, 5);
	// Create Linked List for both sides of the equation.
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

	// Match retrieved coefficients from both lists, and remove the
	// null cases
	list -= list2;
	list.removeNullCoefs();
	list2.removeNullCoefs();

	//If a deterministic equation, end joining Lists, and remove the
	//null cases.
	list.endingJoiningLists(list2);
	list.removeNullCoefs();
	list2.removeNullCoefs();
	list.sort_List();	

	//print Reduced Form and Degree
	list.printReducedForm(usage);
	list.printDegree();

	//is it valid? Continue
	printf(list.validComputorV() ? "true\n" : "Invalid polynomial\n");
	return 0;
}

/*
int main(int argc, char **argv)
{
	Usages	usage;
	int		i;
	
	if (argc >= 2)
	{
		i = 1;
		while (argv[i] && i < argc - 1)
			usage.set_usage(argv[i++]);
		usage.print_usages();//to be removed	
		if (argv[i])
		{
			cout << argv[i]; //stuff to printed to stdout!
			cout << '\n';
		}
	}
	
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

	printf("InitialList - Length: %d\n", list.getLength());
	list.printList();
	
	printf("\nInitialList2 - Length: %d\n", list2.getLength());
	list2.printList();

	list -= list2;

	printf("\n\nUpdatedList - Length: %d\n", list.getLength());
	list.printList();
	printf("\nUpdatedList2 - Length: %d\n", list2.getLength());
	list2.printList();
	
	list.removeNullCoefs();
	list2.removeNullCoefs();

	printf("\n\nRemoved stuff List - Length: %d\n", list.getLength());
	list.printList();
	printf("\nRemoved stuff List2 - Length: %d\n", list2.getLength());
	list2.printList();

	list.endingJoiningLists(list2);
	list.removeNullCoefs();
	list2.removeNullCoefs();
	list.sort_List();	
	
	printf("\n\nSort List - Length: %d\n", list.getLength());
	list.printList();
	printf("\nRemoved stuff List2 - Length: %d\n", list2.getLength());
	list2.printList();

	printf("\nRESULT --------------------\n");
	
	list.printReducedForm();
	list.printDegree();

	printf(list.validComputorV() ? "true\n" : "Invalid polynomial\n");
	return 0;
}
*/
