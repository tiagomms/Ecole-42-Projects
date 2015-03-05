/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:23:51 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/05 20:57:43 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_isspace(int c)
{
	return (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13);
}

static int		ft_calc(const char *str, size_t i, int ok)
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

int				custom_atoi(const char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(*str))
		i = ft_calc(str, 0, 1);
	else if (*str == '+')
		i = ft_calc(str, 1, 1);
	else if (*str == '-')
		i = ft_calc(str, 1, 0);
	else if (ft_isspace(*str))
	{
		str++;
		i = ft_atoi(str);
	}
	if (i <= 0 || i < MAX_ITER)
		return (i);
	ft_putstr_fd("Not a valid entry\n", 2);
	exit(0);
	return (0);
}
