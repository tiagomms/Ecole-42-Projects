/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justify_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:43:24 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:37:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intpwr(size_t n, int base)
{
	size_t	until_0;
	int		nbr_length;

	until_0 = n;
	nbr_length = 1;
	while ((until_0 = until_0 / base))
		nbr_length++;
	return (nbr_length);
}

void	precision_zeros(t_conversion *conversion, char *string,
							t_format *format, int i)
{
	int		r;

	if ((unsigned int)ft_strlen(string) < conversion->precision)
	{
		if (conversion->flags.hashtag)
			r = ft_strlen(string) - i;
		else
			r = ft_strlen(string);
		while ((unsigned int)r < conversion->precision)
		{
			ft_putchar('0');
			r++;
			format->written++;
		}
	}
}
