/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:41:38 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/29 18:47:58 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	if (!(s = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = size;
	while (i)
	{
		s[i] = '\0';
		i--;
	}
	s[i] = '\0';
	return (s);
}
