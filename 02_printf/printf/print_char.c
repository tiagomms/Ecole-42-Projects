/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 13:54:56 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:38:11 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_normal_char(char c, t_format *format,
								t_conversion *conversion)
{
	if (!c)
	{
		while (conversion->width && conversion->width - 1)
		{
			if (conversion->flags.pad_with_zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
			conversion->width--;
			format->written++;
		}
		ft_putchar('\0');
		format->written++;
		return ;
	}
	ft_putchar(c);
	format->written++;
}

static void	print_wide_char(wint_t wint, size_t *written)
{
	if (wint < 0)
		return ;
	print_wint(wint, written);
}

void		print_type_char(va_list arguments, t_format *format,
	t_conversion *conversion)
{
	if (conversion->length == L)
		print_wide_char(va_arg(arguments, wint_t), &format->written);
	else
		print_normal_char(va_arg(arguments, int), format, conversion);
}
