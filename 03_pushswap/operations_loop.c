/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:21:16 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/17 12:21:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_loop(t_format *format,
							int i, int *undo)
{
	if (i == 1 && format->size_a > 1)
		ft_swap(&format->a[0], &format->a[1]);
	else if (i == 2 && format->size_a)
		ft_push(format->b, format->a, &format->size_b, &format->size_a);
	else if (i == 3 && format->size_a)
		rotate(format->a, format->size_a);
	else if (i == 4 && format->size_a)
		reverse_rotate(format->a, format->size_a);
	else if (i == 5 && format->size_b > 1)
		ft_swap(&format->b[0], &format->b[1]);
	else if (i == 6)
		ss(format->a, format->b, format);
	else if (i == 7 && format->size_b)
		ft_push(format->a, format->b, &format->size_a, &format->size_b);
	else if (i == 8 && format->size_b)
		rotate(format->b, format->size_b);
	else if (i == 9 && format->size_a && format->size_b)
		rr(format->a, format->b, format);
	else if (i == 10 && format->size_b)
		reverse_rotate(format->b, format->size_b);
	else if (i == 11 && format->size_a && format->size_b)
		rrr(format->a, format->b, format);
	else
		*undo = 1;
}
