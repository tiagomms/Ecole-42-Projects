/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:04:21 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 15:33:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_m(const char *s, int c, size_t start)
{
	if (s[start] != '\0' && s[start] != c)
		return (ft_strlen_m(s, c, start + 1));
	return (start);
}

static char		*ft_aux(char *s, int c, size_t n)
{
	size_t	a;

	if (n == ft_strlen(s))
		return (c == '\0' ? (s += n) : NULL);
	a = ft_strlen_m(s, c, n + 1);
	if (a == ft_strlen(s))
		return ((s += n));
	return (ft_aux(s, c, a));
}

char			*ft_strrchr(const char *s, int c)
{
	size_t start;

	start = ft_strlen_m(s, c, 0);
	return (ft_aux((char*)s, c, start));
}
