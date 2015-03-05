/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:46:28 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 14:19:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*ft_itoa_uintmax(uintmax_t n)
{
	char	*s;
	int		p;

	p = ft_uintipwr(n);
	if (!(s = (char*)malloc(sizeof(char) * (p + 1))))
		return (NULL);
	s[p] = '\0';
	return (ft_uintchr(s, n, 0, p));
}
