/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 19:08:42 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/17 19:13:42 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	orig_size;

	orig_size = size;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (orig_size + src_len);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
