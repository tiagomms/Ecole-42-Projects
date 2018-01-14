/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:25:30 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/18 01:50:18 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	if (s1)
	{
		while (n > 0)
		{
			if (*s1 == (unsigned char)c)
				return ((void *)(s1));
			s1++;
			n--;
		}
	}
	return (NULL);
}
