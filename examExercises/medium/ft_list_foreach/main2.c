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

#include "ft_list2.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_sort_list(t_list *begin_list, int (*cmp)(int, int));

int cmp(int a, int b)
{
	return (a <= b);
}

t_list	*lst_new(int data)
{
	t_list *new_lst;

	new_lst = malloc(sizeof(t_list));
	new_lst->data = data;
	new_lst->next = NULL;
	return (new_lst);
}

void	print_lst(t_list **begin_list)
{
	t_list *lst;

	lst = *begin_list;
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}

int		main()
{
	t_list *lst;

	lst = lst_new(20);
	lst->next = lst_new(5);
	lst->next->next = lst_new(12);
	lst->next->next->next = lst_new(1);
	lst->next->next->next->next = lst_new(4);
	printf("Before\n");
	print_lst(&lst);	
	ft_sort_list(lst, &cmp);
	printf("\nAFTER \n");
	print_lst(&lst);	
	return (0);
}
