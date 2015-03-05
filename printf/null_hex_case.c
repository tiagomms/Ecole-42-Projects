/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_hex_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 23:16:51 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 23:16:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zeroxprint(char *string, t_format *format,
						t_conversion *conversion)
{
	ft_putchar(string[0]);
	format->written++;
	if (conversion->flags.hashtag && ft_strlen(string) > 1)
	{
		ft_putchar(string[1]);
		format->written++;
		return (2);
	}
	return (1);
}

void	zerocasehex(t_conversion *conversion, t_format *format)
{
	char	*string;
	char	fill;

	if (conversion->precision_set && conversion->precision == 0 &&
					!(conversion->specifier == POINTER))
		return ;
	if (conversion->flags.pad_with_zeros)
		fill = '0';
	else
		fill = ' ';
	if (conversion->precision_set && conversion->precision == 0)
		string = ft_strdup("0x");
	else if (conversion->flags.hashtag && conversion->specifier == POINTER)
		string = ft_strdup("0x0");
	else
		string = ft_strdup("0");
	if (conversion->flags.left_justify)
		ft_puthex_justify_left(string, conversion, ' ', format);
	else
		ft_puthex_justify_right(string, conversion, fill, format);
}
