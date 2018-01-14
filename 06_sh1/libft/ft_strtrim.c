/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:07:52 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/18 02:50:48 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	char	*new_string;

	if (!s)
		return (NULL);
	new_string = ft_strnew(ft_strlen(s));
	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (i < (ft_strlen(s)))
	{
		new_string[k] = s[i];
		k++;
		i++;
	}
	k = k - 1;
	while (new_string[k] == ' ' || new_string[k] == '\n' ||
			new_string[k] == '\t')
	{
		new_string[k] = '\0';
		k--;
	}
	return (new_string);
}
