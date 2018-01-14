/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:16:31 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/24 16:16:33 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_create_elem(void *data)
{
	t_list *new_thingy;

	new_thingy = malloc(sizeof(t_list));
	new_thingy->data = data;
	new_thingy->next = NULL;
	return (new_thingy);
}
