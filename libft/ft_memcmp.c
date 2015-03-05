/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:46:02 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/10 16:16:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char *d1;
	unsigned const char *d2;

	i = 0;
	d2 = (unsigned const char *)s2;
	d1 = (unsigned const char *)s1;
	while (i < n)
	{
		if (d1[i] == d2[i])
			i++;
		else
			return (d1[i] - d2[i]);
	}
	return (0);
}
