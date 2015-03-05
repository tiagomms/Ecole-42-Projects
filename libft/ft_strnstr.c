/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:45:04 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/13 00:37:34 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_index(char *s1, char *s2, size_t beg, size_t idx)
{
	if (s1[beg + idx] == '\0' && s2[idx] != '\0')
		return (-1);
	if (s2[idx] == '\0')
		return (beg);
	if (s1[beg + idx] != s2[idx])
		return (ft_index(s1, s2, beg + 1, 0));
	return (ft_index(s1, s2, beg, idx + 1));
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*aux1;
	char	*aux2;
	size_t	res;

	aux1 = (char *)s1;
	aux2 = (char *)s2;
	if (aux2 == NULL)
		return (aux1);
	res = ft_index(aux1, aux2, 0, 0);
	if (res > ft_strlen(s1))
		return (NULL);
	if (res + ft_strlen(s2) <= n)
		return ((aux1 += res));
	return (NULL);
}
