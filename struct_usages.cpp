// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   struct_usages.cpp                                  :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/05/21 15:49:17 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/03 21:34:26 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
using	namespace std; 

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
	void set_usage(char *arg);
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

//this is how static members are implemented
bool	Usages::natural_display__n = 0; 
bool	Usages::equation_graph__g = 0;
bool	Usages::degree_colors__c = 0;
bool	Usages::interm_steps__i = 0;


void	Usages::set_usage(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		i++;
		while (arg[i] && (arg[i] == 'n' || arg[i] == 'g' || arg[i] == 'c'))
		{
			natural_display__n = (natural_display__n ||  arg[i] == 'n');
			equation_graph__g = (equation_graph__g || arg[i] == 'g');
			degree_colors__c = (degree_colors__c || arg[i] == 'c');
			i++;
		}
		if (arg[i])
			print_error(arg);
	}
	else
		print_error(arg);
}	

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
			cout << argv[i]; //stuff to printed to stdout!
	}
	cout << '\n';
	return 0;
}
