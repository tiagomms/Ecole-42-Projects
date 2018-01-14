/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:15:47 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/24 16:15:51 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list->next == NULL && nbr >= 2)
		return (NULL);
	if (nbr == 1)
		return (begin_list);
	return (ft_list_at(begin_list->next, nbr - 1));
}
