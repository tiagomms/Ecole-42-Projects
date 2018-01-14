/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:00:01 by exam              #+#    #+#             */
/*   Updated: 2015/05/13 10:21:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_int_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sorting_algo(t_list **begin_lst, int (*cmp)(int, int))
{
	int		changed;
	t_list	*lst;

	changed = 1;
	while (changed)
	{
		changed = 0;
		lst = *begin_lst;
		while (lst->next)
		{
			if (!cmp(lst->data, lst->next->data))
			{
				ft_int_swap(&(lst->data), &(lst->next->data));
				changed = 1;
			}
			lst = lst->next;
		}
	}
}

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	sorting_algo(&lst, cmp);
	return (lst);
}
