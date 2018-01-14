/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:18:52 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/31 13:01:13 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list		*current_node;
	t_list		*following_node;
	t_list		*previous_node;

	current_node = *begin_list;
	previous_node = NULL;
	while (current_node != NULL)
	{
		following_node = current_node->next;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = following_node;
	}
	*begin_list = previous_node;
}
