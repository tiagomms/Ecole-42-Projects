/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:52:41 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/11 18:57:44 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t i)
{
	size_t r;
	size_t k;

	r = 0;
	k = 0;
	while (s1[r] != '\0')
		r++;
	while (s2[k] != '\0' && k < i)
	{
		s1[r] = s2[k];
		r++;
		k++;
	}
	s1[r] = '\0';
	return (s1);
}
