/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:47:29 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/27 14:56:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char*)s;
	if (!aux)
		return (NULL);
	while (*aux != '\0' && *aux != c)
		aux++;
	if (*aux == c)
		return (aux);
	return (NULL);
}
