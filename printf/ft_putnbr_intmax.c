/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_intmax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:17:21 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 14:25:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	ft_abs_intmax(intmax_t n)
{
	return (n < 0 ? -n : n);
}

static void		ft_help(intmax_t n, t_format *format)
{
	if (n >= 10 || n <= -10)
		ft_help(n / 10, format);
	ft_putchar(ft_abs_intmax(n % 10) + '0');
	format->written++;
}

void			ft_putnbr_intmax(intmax_t n, t_format *format,
	t_conversion *conversion)
{
	if (n < 0)
	{
		ft_putchar('-');
		format->written++;
	}
	if (n > 0 && conversion->flags.show_sign)
	{
		ft_putchar('+');
		format->written++;
	}
	else if (n > 0 && conversion->flags.positive_values_begin_blank)
	{
		ft_putchar(' ');
		format->written++;
	}
	ft_help(n, format);
}
