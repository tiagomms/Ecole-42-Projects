/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:16:15 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/24 16:16:18 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_destroy(t_list *list)
{
	if (list->next != NULL)
		ft_destroy(list->next);
	free(list);
}

void			ft_list_clear(t_list **begin_list)
{
	ft_destroy(*begin_list);
	*begin_list = NULL;
}
