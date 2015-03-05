/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:30:08 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 20:06:58 by tsilva           ###   ########.fr       */
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

char			*ft_strstr(const char *s1, const char *s2)
{
	char	*aux1;
	char	*aux2;
	size_t	res;

	aux1 = (char *)s1;
	aux2 = (char *)s2;
	if (aux2 == NULL)
		return (aux1);
	res = ft_index(aux1, aux2, 0, 0);
	return (res > ft_strlen(s1) ? NULL : (aux1 += res));
}
