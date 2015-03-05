/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 00:47:57 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/13 20:57:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*lst;
	t_list	*temp;
	t_list	*frst;

	if (alst)
	{
		frst = *alst;
		lst = frst->next;
		temp = frst->next;
		while (temp != NULL)
		{
			lst = lst->next;
			del(temp->content, temp->content_size);
			temp->next = NULL;
			free(temp);
			temp = lst;
		}
		del(frst->content, frst->content_size);
		frst->next = NULL;
		free(*alst);
		*alst = NULL;
	}
}
