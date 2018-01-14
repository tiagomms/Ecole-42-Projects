/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:39:45 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/29 17:43:46 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	size_t			l;

	if (!(aux = (char*)malloc(sizeof(char) * len + 1))
			|| start + len > ft_strlen(s))
		return (NULL);
	l = 0;
	while (l < len)
	{
		aux[l] = s[l + start];
		l++;
	}
	aux[l] = '\0';
	return (aux);
}
