/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:18:53 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/26 10:24:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_isspace(int c)
{
	return (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13);
}

static int			ft_calc(const char *str, size_t i, int ok)
{
	size_t		j;
	int			res;

	j = i;
	res = 0;
	while (ft_isspace(*(str + j)) && *(str + j) != '\0')
		j++;
	while (ft_isdigit(*(str + j)) && *(str + j) != '\0')
	{
		if (ok)
			res = res * 10 + (*(str + j) - 48);
		else
			res = res * 10 - (*(str + j) - 48);
		if ((res <= -1 && ok) || (res >= 1 && !ok))
			break ;
		j++;
	}
	if (*(str + j) == '\0')
		return (res);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int					custom_atoi(const char *str)
{
	if (ft_isdigit(*str))
		return (ft_calc(str, 0, 1));
	if (*str == '+')
		return (ft_calc(str, 1, 1));
	if (*str == '-')
		return (ft_calc(str, 1, 0));
	if (ft_isspace(*str))
	{
		str++;
		return (ft_atoi(str));
	}
	ft_putstr_fd("Error\n", 2);
	exit(0);
	return (0);
}
