/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:50:44 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 14:48:28 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;

	if (!(s = (unsigned char*)malloc(sizeof(char) * size)) || size == 0)
		return (NULL);
	ft_bzero(s, size);
	return ((void*)s);
}
