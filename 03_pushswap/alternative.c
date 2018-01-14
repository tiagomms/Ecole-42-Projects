/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:49:38 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/24 16:49:42 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_back(t_format *format)
{
	while (format->size_b > 1)
	{
		ft_push(format->a, format->b, &format->size_a, &format->size_b);
		write(1, "pa ", 3);
	}
	if (format->size_b > 0)
	{
		ft_push(format->a, format->b, &format->size_a, &format->size_b);
		write(1, "pa", 2);
	}
}

static void		reverse_back(int *counter, t_format *format, int *a)
{
	int	i;

	i = 0;
	while (a[i] != *counter)
		i++;
	if (i < format->size_a / 2)
	{
		while (!(a[0] == *counter))
		{
			rotate(a, format->size_a);
			write(1, "ra ", 3);
		}
	}
	else
	{
		while (!(a[0] == *counter))
		{
			reverse_rotate(a, format->size_a);
			write(1, "rra ", 4);
		}
	}
}

void			alternative(int *a, int *b, t_format *format)
{
	int		counter;

	counter = 0;
	format->a = a;
	format->b = b;
	while (format->size_a > 1)
	{
		if (a[0] == counter)
		{
			ft_push(format->b, format->a, &format->size_b, &format->size_a);
			write(1, "pb ", 3);
			counter++;
		}
		else
			reverse_back(&counter, format, a);
	}
	push_back(format);
}
