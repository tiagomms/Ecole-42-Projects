/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:19:01 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/09 17:40:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	char			*aux;
	unsigned int	i;

	aux = s;
	i = 0;
	while (aux[i] != '\0')
	{
		f(i, &(aux[i]));
		i++;
	}
}
