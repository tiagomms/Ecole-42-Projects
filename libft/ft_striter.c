/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:05:15 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/13 23:58:52 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int length;
	int counter;

	counter = 0;
	if (s != NULL && f != NULL)
	{
		length = ft_strlen(s);
		while (counter < length)
		{
			(*f)(s + counter);
			counter++;
		}
	}
}
