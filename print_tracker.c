/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tracker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 19:30:10 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/18 19:30:11 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turn_tracker_string(int *tracker, int size, int i)
{
	while (++i < size)
	{
		if (tracker[i] == 1)
			write(1, "sa", 2);
		else if (tracker[i] == 2)
			write(1, "pb", 2);
		else if (tracker[i] == 3)
			write(1, "ra", 2);
		else if (tracker[i] == 4)
			write(1, "rra", 3);
		else if (tracker[i] == 5)
			write(1, "sb", 2);
		else if (tracker[i] == 6)
			write(1, "ss", 2);
		else if (tracker[i] == 7)
			write(1, "pa", 2);
		else if (tracker[i] == 8)
			write(1, "rb", 2);
		else if (tracker[i] == 9)
			write(1, "rr", 2);
		else if (tracker[i] == 10 || tracker[i] == 11)
			write(1, (tracker[i] == 10) ? "rrb" : "rrr", 3);
		write(1, (i < size - 1) ? " " : "\n", 1);
	}
}
