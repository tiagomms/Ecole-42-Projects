/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:38:55 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/30 21:26:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		counter;
	int		length;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = ft_strnew(length);
	counter = 0;
	while (s[counter] != '\0')
	{
		result[counter] = (*f)(s[counter]);
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
