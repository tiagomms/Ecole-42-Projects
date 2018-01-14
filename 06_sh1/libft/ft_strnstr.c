/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:01:11 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/17 18:03:04 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_a(const char *haystack, const char *needle, size_t i, size_t x)
{
	size_t r;
	size_t offset;

	r = 0;
	offset = 0;
	if (needle[r] == '\0' || needle == NULL)
		return ((char *)haystack);
	while (i + offset < x && haystack[i] != '\0')
	{
		if (needle[r] == haystack[i + offset])
		{
			r++;
			offset++;
		}
		else
		{
			i++;
			offset = 0;
			r = 0;
		}
		if (needle[r] == '\0')
			return ((char *)haystack + i);
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t x)
{
	size_t	i;

	i = 0;
	return (ft_a(haystack, needle, i, x));
}
