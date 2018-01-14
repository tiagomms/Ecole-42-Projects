/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 17:05:59 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 17:32:58 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

static int	ft_strcmp(char *str1, char *str2)
{
	size_t i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

static int	do_op(int a, char *op, int b)
{
	if (!ft_strcmp(op, "+"))
		return (a + b);
	else if (!ft_strcmp(op, "*"))
		return (a * b);
	else if (!ft_strcmp(op, "/"))
		return (a / b);
	else if (!ft_strcmp(op, "%"))
		return (a % b);
	else
		return (a - b);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		printf("%d", do_op(atoi(argv[1]), argv[2], atoi(argv[3])));
	printf("\n");
}
