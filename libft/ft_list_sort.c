/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:23:54 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/03 11:28:31 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_sort(t_list **list, int (*compare)(void*, void*))
{
	t_list	*lister;

	lister = *list;
	while (lister->next)
	{
		if (compare(lister->data, lister->next->data) > 0)
		{
			ft_ptrswp(&lister->data, &lister->next->data);
			lister = *list;
			continue ;
		}
		lister = lister->next;
	}
}
