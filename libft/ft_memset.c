/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:52:21 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/10 15:59:52 by tsilva           ###   ########.fr       */
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
	string[i] = '\0';
	return (b);
}
