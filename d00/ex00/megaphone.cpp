// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   megaphone.cpp                                      :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/15 14:35:51 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/15 14:47:17 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int		main(int argc, char **argv)
{
	int 	i;
	int 	j;
	char	c;

	if (argc >= 2)
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while ((c = argv[i][j]))
			{
				if (c >= 'a' && c <= 'z')
					c -= 32;
				std::cout << c;
				j++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
