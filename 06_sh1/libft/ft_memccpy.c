/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 21:17:05 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/18 19:40:21 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	*s1;

	i = 0;
	s2 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
		{
			s2[i] = s1[i];
			return (dst + i + 1);
		}
		else
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (NULL);
}
