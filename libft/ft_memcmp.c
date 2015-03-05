/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:48:18 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/29 18:32:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*f1;
	unsigned char	*f2;
	size_t			i;

	f1 = (unsigned char*)s1;
	f2 = (unsigned char*)s2;
	i = n;
	while (i && *f1 == *f2)
	{
		f1++;
		f2++;
		i--;
	}
	return (i == 0 ? 0 : (unsigned char)*f1 - (unsigned char)*f2);
}
