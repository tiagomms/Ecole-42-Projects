/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:28:20 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/22 17:28:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_same_number(int *a, int stack_size)
{
	int	current_pos;
	int	i;

	current_pos = 0;
	while (current_pos < stack_size)
	{
		i = -1;
		while (++i < stack_size)
		{
			if (i == current_pos)
				continue ;
			if (a[current_pos] == a[i])
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
		}
		current_pos++;
	}
}

void	sort_convert_numbers(int *original, int *a, t_format *format)
{
	int	current_pos;
	int	i;

	current_pos = 0;
	while (current_pos < format->stack_size)
	{
		i = 0;
		while (i < format->stack_size)
		{
			if (i != current_pos)
				if (original[current_pos] > original[i])
					a[current_pos]++;
			i++;
		}
		current_pos++;
	}
	check_if_same_number(a, format->stack_size);
}
