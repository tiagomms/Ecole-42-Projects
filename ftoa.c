/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:54:05 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/05 14:54:11 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_uintipwr(uintmax_t n)
{
	return (n < 10 ? 1 : 1 + ft_uintipwr(n / 10));
}

static char		*ft_uintchr(char *s, uintmax_t n, size_t lim, size_t p)
{
	if (lim == p)
		return (s);
	s[p - 1] = (n % 10) + 48;
	return (ft_uintchr(s, n / 10, lim, p - 1));
}

static char		*ft_itoa_uintmax(uintmax_t n)
{
	char	*s;
	int		p;

	p = ft_uintipwr(n);
	if (!(s = (char*)malloc(sizeof(char) * (p + 1))))
		return (NULL);
	s[p] = '\0';
	return (ft_uintchr(s, n, 0, p));
}

static char		*details_ftoa(char *str_number, double rest, double n)
{
	if ((((uintmax_t)floor(rest * 10)) % 10) > 5)
		rest = ceil(rest);
	else
		rest = floor(rest);
	str_number = ft_strjoin(str_number, ft_itoa_uintmax((uintmax_t)rest));
	if (n < 0)
		str_number = ft_strjoin("-", str_number);
	else
		str_number = ft_strjoin(" ", str_number);
	return (str_number);
}

char			*ft_ftoa(double n, int precision)
{
	double	rest;
	char	*str_number;
	int		i;
	double	abs_n;

	i = 0;
	abs_n = ft_abs_double(n);
	str_number = ft_itoa_uintmax((uintmax_t)floor(abs_n));
	rest = abs_n - floor(abs_n);
	str_number = ft_strjoin(str_number, ".");
	while (i < precision && floor(rest * 10) == 0.0)
	{
		rest *= 10;
		str_number = ft_strjoin(str_number, "0");
		i++;
	}
	while (i < precision)
	{
		rest *= 10;
		i++;
	}
	return (details_ftoa(str_number, rest, n));
}
