/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:59:36 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/30 21:08:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	s1 = dst;
	s2 = (unsigned char*)src;
	i = n;
	while (i)
	{
		*s1++ = *s2++;
		i--;
	}
	return (dst);
}
