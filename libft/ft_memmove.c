/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:01:39 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/13 15:14:15 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_memcpy((void *)new, src, len);
	ft_memcpy(dst, (const void *)new, len);
	return (dst);
}
