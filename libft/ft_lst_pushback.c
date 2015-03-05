/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 23:42:07 by tsilva            #+#    #+#             */
/*   Updated: 2014/12/14 00:09:46 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback(t_list **begin_list, void *content, size_t contentsize)
{
	t_list	*new_one;

	new_one = ft_lstnew(content, contentsize);
	if (!(*begin_list))
		*begin_list = new_one;
	else
		ft_lstlast(*begin_list)->next = new_one;
}
