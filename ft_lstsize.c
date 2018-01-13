/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 23:36:06 by tsilva            #+#    #+#             */
/*   Updated: 2014/12/13 23:55:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(t_list **list)
{
	t_list	*beginlist;
	size_t	list_size;

	list_size = 0;
	if (list && *list)
	{
		beginlist = *list;
		while (beginlist)
		{
			list_size++;
			beginlist = beginlist->next;
		}
	}
	return (list_size);
}
