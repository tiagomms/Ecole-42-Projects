/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlerotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:06:35 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/16 18:06:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *array, int size)
{
	int i;
	int first;

	if (size < 2)
		return ;
	i = 0;
	first = array[0];
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = first;
}

void	rr(int *a, int *b, t_format *format)
{
	if (format->size_a < 2 || format->size_b < 2)
		return ;
	rotate(a, format->size_a);
	rotate(b, format->size_b);
}

void	reverse_rotate(int *array, int size)
{
	int i;
	int last;

	if (size < 2)
		return ;
	i = size;
	last = array[i - 1];
	while (--i)
		array[i] = array[i - 1];
	array[i] = last;
}

void	rrr(int *a, int *b, t_format *format)
{
	if (format->size_a < 2 || format->size_b < 2)
		return ;
	reverse_rotate(a, format->size_a);
	reverse_rotate(b, format->size_b);
}
