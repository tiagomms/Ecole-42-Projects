/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:36:58 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 18:23:11 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(int c)
{
	return (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13);
}

static long long	ft_calc(const char *str, size_t i, int ok)
{
	size_t		j;
	long long	res;

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
		if (res <= -1 && ok)
			return (-1);
		if (res >= 1 && !ok)
			return (0);
		j++;
	}
	return (res);
}

int					ft_atoi(const char *str)
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
	return (0);
}
