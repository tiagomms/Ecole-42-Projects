/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 23:35:49 by tsilva            #+#    #+#             */
/*   Updated: 2014/12/13 23:39:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *begin_list)
{
	if (begin_list)
	{
		if (begin_list->next)
			return (ft_lstlast(begin_list->next));
		else
			return (begin_list);
	}
	return (NULL);
}
