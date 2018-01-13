/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_widths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 19:05:15 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 14:03:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_width_spaces(char fill, size_t length, t_format *format,
									t_conversion *conversion)
{
	size_t	w;

	if (fill != ' ')
		return ;
	w = 0;
	while (w + length < conversion->width)
	{
		ft_putchar(fill);
		w++;
		format->written++;
	}
}

void		add_width_zeros(char fill, size_t length,
								t_format *format, t_conversion *conversion)
{
	size_t	w;

	if (fill != '0')
		return ;
	w = 0;
	while (w + length < conversion->width)
	{
		ft_putchar(fill);
		w++;
		format->written++;
	}
}
