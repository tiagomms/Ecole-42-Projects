/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:17:11 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/24 16:17:12 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}
