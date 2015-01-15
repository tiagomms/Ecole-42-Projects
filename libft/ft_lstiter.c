/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:31:07 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/13 15:55:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*beg;

	if (lst)
	{
		beg = lst;
		f(beg);
		while (beg->next != NULL)
		{
			beg = beg->next;
			f(beg);
		}
	}
}
