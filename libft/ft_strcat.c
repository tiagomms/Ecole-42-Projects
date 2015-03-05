/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:33:39 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/11 18:56:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[r] != '\0')
	{
		s1[i] = s2[r];
		i++;
		r++;
	}
	s1[i] = '\0';
	return (s1);
}
