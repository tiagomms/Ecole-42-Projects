/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:45:07 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/29 18:35:34 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*aux;

	aux = (char *)s2;
	if (aux)
	{
		if (s1)
			len = ft_strlen(s1);
		else
			len = 0;
		i = 0;
		while (s2[i++] != '\0')
			s1[i + len - 1] = s2[i - 1];
		s1[i + len - 1] = '\0';
	}
	return (s1);
}
