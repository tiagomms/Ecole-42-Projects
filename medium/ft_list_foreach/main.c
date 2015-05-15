/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 20:42:41 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 20:52:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

t_list	*lst_new(void *data)
{
	t_list *new_lst;

	new_lst = malloc(sizeof(t_list));
	new_lst->data = data;
	new_lst->next = NULL;
	return (new_lst);
}

void	print_data(void *data)
{
	printf("%s\n", (char*)data);
}

int		main()
{
	char	str0[] = "Hello-";
	char	str1[] = "World-";
	char	str2[] = "sub-";
	char	str3[] = "str-";
	char	str4[] = "party-";	
	t_list *lst;

	lst = lst_new((void*)str0);
	lst->next = lst_new((void*)str1);
	lst->next->next = lst_new((void*)str2);
	lst->next->next->next = lst_new((void*)str3);
	lst->next->next->next->next = lst_new((void*)str4);	
	ft_list_foreach(lst, &print_data);
	return (0);
}
