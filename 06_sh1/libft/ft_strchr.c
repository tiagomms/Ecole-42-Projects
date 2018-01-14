/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:08:08 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/11 19:37:46 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		to_find;
	char	*s2;

	if (!s)
		return (NULL);
	to_find = (char)c;
	s2 = (char *)s;
	while (*s2 != '\0')
	{
		if (*s2 == to_find)
			return (s2);
		s2++;
	}
	if (*s2 == '\0' && to_find == '\0')
		return (s2);
	return (NULL);
}
