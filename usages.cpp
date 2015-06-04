// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   usages.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/04 18:30:17 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/04 18:35:35 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.h"

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
		while (arg[i] &&
			   (arg[i] == 'n' || arg[i] == 'g' || arg[i] == 'c' || arg[i] == 'i'))
		{
			natural_display__n = (natural_display__n ||  arg[i] == 'n');
			equation_graph__g = (equation_graph__g || arg[i] == 'g');
			degree_colors__c = (degree_colors__c || arg[i] == 'c');
			interm_steps__i = (interm_steps__i || arg[i] == 'i');			
			i++;
		}
		if (arg[i])
			print_error(arg);
	}
	else
		print_error(arg);
}
