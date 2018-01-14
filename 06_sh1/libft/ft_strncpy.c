/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:15:28 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/21 17:57:07 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t i)
{
	size_t r;

	if (!src)
		return (NULL);
	r = 0;
	while (src[r] != '\0' && r < i)
	{
		dest[r] = src[r];
		r++;
	}
	while (r < i)
	{
		dest[r] = '\0';
		r++;
	}
	return (dest);
}
