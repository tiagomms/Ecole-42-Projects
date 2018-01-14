/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 21:46:22 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/10 22:42:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*curr_node;
	t_list		*last_node;

	last_node = *begin_list;
	curr_node = *begin_list;
	while (curr_node && curr_node->next)
	{
		if (cmp(curr_node->data, data_ref))
		{
			last_node->next = curr_node->next;
			last_node = curr_node;
			curr_node = curr_node->next;
			free(last_node);
		}
		else
		{
			last_node = curr_node;
			curr_node = curr_node->next;
		}
	}
}
