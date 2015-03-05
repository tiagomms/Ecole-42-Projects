/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:26:05 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/22 17:26:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	correct_order_zero_ops(int *a, t_format *format)
{
	int i;

	i = 0;
	while (i < format->stack_size)
	{
		if (a[i] != i)
			break ;
		i++;
	}
	if (i == format->stack_size)
	{
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

t_bool	correct_order(int *a, t_format *format, int *tracker, int ops_possible)
{
	int	i;

	if (format->size_a != format->stack_size)
		return (0);
	i = 0;
	while (i < format->stack_size)
	{
		if (a[i] != i)
			break ;
		i++;
	}
	if (i == format->stack_size)
	{
		turn_tracker_string(tracker, ops_possible, -1);
		exit(0);
	}
	return (0);
}
