/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:17:48 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/24 16:17:50 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	int			i;
	t_list		*first_elem;

	if (ac == 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ft_list_push_front(&first_elem, av[i]);
		i++;
	}
	return (first_elem);
}
