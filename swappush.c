/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:27:35 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/16 18:27:46 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	ss(int *a, int *b, t_format *format)
{
	if (format->size_a < 2 || format->size_b < 2)
		return ;
	ft_swap(&a[0], &a[1]);
	ft_swap(&b[0], &b[1]);
}

void	ft_push(int *add_first, int *remove_first,
				int *size_add, int *size_remove)
{
	int		i;

	i = *size_add;
	while (i-- > 0)
		add_first[i + 1] = add_first[i];
	add_first[0] = remove_first[0];
	(*size_add)++;
	(*size_remove)--;
	if (!(*size_remove))
		remove_first[0] = 50;
	i = 0;
	while (i < *size_remove)
	{
		remove_first[i] = remove_first[i + 1];
		i++;
	}
}
