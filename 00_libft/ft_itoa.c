/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:03:12 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 18:23:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intpwr(int n)
{
	if (n >= 0)
		return (n < 10 ? 1 : 1 + ft_intpwr(n / 10));
	return (n > -10 ? 1 : 1 + ft_intpwr(n / 10));
}

static char	*ft_intchr(char *s, int n, size_t lim, size_t p)
{
	if (lim == p)
		return (s);
	if (n < 0)
		s[p - 1] = -(n % 10) + 48;
	else
		s[p - 1] = (n % 10) + 48;
	return (ft_intchr(s, n / 10, lim, p - 1));
}

char		*ft_itoa(int n)
{
	char	*s;
	int		p;

	p = ft_intpwr(n);
	if (n < 0)
		p++;
	if (!(s = (char*)malloc(sizeof(char) * (p + 1))))
		return (NULL);
	s[p] = '\0';
	if (n >= 0)
		return (ft_intchr(s, n, 0, p));
	s[0] = '-';
	return (ft_intchr(s, n, 1, p));
}
