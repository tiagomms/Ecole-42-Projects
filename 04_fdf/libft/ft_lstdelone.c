/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:40:48 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/13 20:57:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*lst;

	if (alst)
	{
		lst = *alst;
		del(lst->content, lst->content_size);
		lst->next = NULL;
		free(*alst);
		*alst = NULL;
	}
}
