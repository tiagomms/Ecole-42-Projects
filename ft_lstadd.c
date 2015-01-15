/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:16:14 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/30 21:52:12 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*original_list;
	t_list	*new_head;

	if (new && alst)
	{
		if (!(*alst))
		{
			*alst = new;
			(*alst)->next = NULL;
		}
		else
		{
			original_list = *alst;
			new_head = new;
			new_head->next = original_list;
			*alst = new_head;
		}
	}
}
