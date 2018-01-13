/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:27:18 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/09 20:53:41 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*s;
	size_t	i;

	s = dst;
	i = 0;
	while (src[i] != 0 && i < n)
	{
		s[i] = src[i];
		i++;
	}
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (dst);
}
