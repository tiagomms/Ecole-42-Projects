/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:38:55 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/19 23:19:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*fresh;

	i = 0;
	if (!size)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * size);
	if (!fresh)
		return (NULL);
	while (i < size)
	{
		fresh[i] = 0;
		i++;
	}
	return ((void *)fresh);
}
