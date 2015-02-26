/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:01:11 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/18 20:56:36 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_a_k(const char *haystack, const char *needle, int i, int r)
{
	int offset;

	offset = 0;
	if (needle[r] == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (needle[r] == haystack[i + offset])
		{
			offset++;
			r++;
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

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	return (ft_a_k(haystack, needle, i, r));
}
