/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:52:21 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/10 15:59:52 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	f;
	size_t			i;
	char			*string;

	string = (char *)b;
	f = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		string[i] = f;
		i++;
	}
	return (b);
}
