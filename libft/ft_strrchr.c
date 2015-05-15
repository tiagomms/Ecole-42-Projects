/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:38:56 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/11 19:38:20 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		k;
	int		to_find;
	char	*s2;

	to_find = (char)c;
	s2 = (char *)s;
	i = 0;
	k = -1;
	while (s2[i] != '\0')
	{
		if (s2[i] == to_find)
			k = i;
		i++;
	}
	if (s2[i] == '\0' && to_find == '\0')
		return (s2 + i);
	if (k >= 0)
		return (s2 + k);
	return (NULL);
}
