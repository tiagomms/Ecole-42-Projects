/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:25:44 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/14 14:29:50 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	length;
	unsigned int	counter;

	counter = 0;
	if (s != NULL && f != NULL)
	{
		length = ft_strlen(s);
		while (counter < length)
		{
			(*f)(counter, s + counter);
			counter++;
		}
	}
}
