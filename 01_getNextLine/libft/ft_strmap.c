/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:27:43 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 15:15:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f) (char))
{
	char	*aux;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	aux = (char*)malloc(sizeof(char) * (i + 1));
	while (i-- > 0)
		aux[i] = f(s[i]);
	aux[ft_strlen(s)] = '\0';
	return (aux);
}
