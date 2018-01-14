/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:36:50 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/13 20:20:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*aux;
	t_list	*temp;

	aux = lst;
	new = NULL;
	if (!aux)
		return (NULL);
	if (!(temp = f(aux)))
		return (NULL);
	new = temp;
	while (aux->next != NULL)
	{
		while (new->next != NULL)
			new = new->next;
		aux = aux->next;
		if ((temp = f(aux)) == NULL)
			return (NULL);
		new->next = temp;
	}
	return (new);
}
