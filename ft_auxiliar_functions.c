/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliar_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:40:18 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 17:06:44 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_in_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + (b));
}

double	ft_abs_d(double n)
{
	return (n < 0 ? -n : n);
}

int		hex_2_decimal(char c)
{
	int		rem;

	if (c == 'A' || c == 'a')
		rem = 10;
	else if (c == 'B' || c == 'b')
		rem = 11;
	else if (c == 'C' || c == 'c')
		rem = 12;
	else if (c == 'D' || c == 'd')
		rem = 13;
	else if (c == 'E' || c == 'e')
		rem = 14;
	else if (c == 'F' || c == 'f')
		rem = 15;
	else
		rem = c - 48;
	return (rem);
}

void	ft_min_max_nbr_list(t_list **list, t_info *l)
{
	size_t	i;
	t_list	*list_of_lines;

	list_of_lines = *list;
	l->min_mid_max[0] = 2147483647;
	l->min_mid_max[1] = 0;
	l->min_mid_max[2] = -2147483648;
	while (list_of_lines)
	{
		i = 0;
		while (i < list_of_lines->content_size)
		{
			if (*((int*)list_of_lines->content + i) < l->min_mid_max[0])
				l->min_mid_max[0] = *((int*)list_of_lines->content + i);
			if (*((int*)list_of_lines->content + i) > l->min_mid_max[2])
				l->min_mid_max[2] = *((int*)list_of_lines->content + i);
			i++;
		}
		list_of_lines = list_of_lines->next;
	}
	l->min_mid_max[1] = (l->min_mid_max[2] + l->min_mid_max[0]) / 2;
}

size_t	ft_max_contentsize(t_list **list)
{
	t_list	*beginlist;
	size_t	max_content;

	max_content = 0;
	if (list && *list)
	{
		beginlist = *list;
		while (beginlist)
		{
			if (max_content < beginlist->content_size)
				max_content = beginlist->content_size;
			beginlist = beginlist->next;
		}
	}
	return (max_content);
}
