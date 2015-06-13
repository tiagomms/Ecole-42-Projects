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
//   Updated: 2015/06/13 11:19:59 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./includes/computorv1.hpp"

bool	Usages::natural_display__n = 0; 

void	Usages::set_usage(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		i++;
		while (arg[i] && arg[i] == 'n')
		{
			natural_display__n = (natural_display__n ||  arg[i] == 'n');
			i++;
		}
		if (arg[i])
			print_error(arg);
	}
	else
		print_error(arg);
}
