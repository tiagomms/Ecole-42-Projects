/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:15:54 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/27 17:02:19 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +
						1))))
		return (NULL);
	i = 0;
	while (s1[i++] != '\0')
		s[i - 1] = s1[i - 1];
	j = 0;
	while (s2[j++] != '\0')
		s[i - 1 + j - 1] = s2[j - 1];
	s[i + j - 2] = '\0';
	return (s);
}
