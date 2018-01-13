/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:59:10 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/30 21:27:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	unsigned int	length;
	char			*new;

	if (s == NULL || f == NULL)
		return (NULL);
	counter = 0;
	length = ft_strlen(s);
	new = ft_strnew(length);
	while (s[counter] != '\0')
	{
		new[counter] = f(counter, s[counter]);
		counter++;
	}
	new[counter] = '\0';
	return (new);
}
