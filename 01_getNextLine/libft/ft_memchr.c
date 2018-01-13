/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:29:47 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/30 21:09:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char*)b;
	i = n;
	while (i && *s != (unsigned char)c)
	{
		i--;
		s++;
	}
	return (i == 0 ? NULL : s);
}
