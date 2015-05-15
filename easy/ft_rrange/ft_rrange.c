/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 20:33:57 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 20:33:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int ft_sgn(int n)
{
	return (n < 0 ? -1 : 1);
}

int *ft_rrange(int start, int end)
{
	int *int_array;
	int increment;
	int i;
	int nbr;

	increment = ft_sgn(start - end);
	i = 0;
	nbr = end;
	int_array = malloc(sizeof(int) * (ft_abs(start - end) + 1));
	while (i <= ft_abs(start - end))
	{
		int_array[i++] = nbr;
		nbr += increment;
	}
	return (int_array);
}
