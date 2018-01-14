/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 10:52:21 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/03 11:30:18 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_list_remove_node(t_list **original,
											t_list *to_remove,
											void (*free_inside)(void*))
{
	t_list				*old_one;

	if (original && *original && to_remove)
	{
		if (*original == to_remove)
		{
			old_one = *original;
			*original = (*original)->next;
			if (free_inside)
				free_inside(old_one->data);
		}
		else
			ft_list_remove_node(&((*original)->next), to_remove, free_inside);
	}
}
