/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:17:35 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/24 16:17:37 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_one;

	new_one = ft_list_create_elem(data);
	new_one->next = *begin_list;
	*begin_list = new_one;
}
