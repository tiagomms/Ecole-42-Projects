/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 21:18:04 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/26 01:13:49 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		length2;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * length + 1);
	if (!new_string)
		return (NULL);
	length = 0;
	length2 = 0;
	while (s1[length] != '\0')
	{
		new_string[length] = s1[length];
		length++;
	}
	while (s2[length2] != '\0')
	{
		new_string[length] = s2[length2];
		length++;
		length2++;
	}
	new_string[length] = '\0';
	return (new_string);
}
