/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 20:39:37 by tsilva            #+#    #+#             */
/*   Updated: 2014/09/01 22:59:41 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

int		main()
{
	char *s_num;
	char *s_num2;

	s_num = "6996123";
	s_num2 = strdup("69696969");
	fprintf(stdout, "s_num  %s  %d\n", s_num, atoi(s_num));
	fprintf(stdout, "num - %s  %d\n", s_num2, ft_atoi(s_num2));
	return (0);
}
	
	
	
	
