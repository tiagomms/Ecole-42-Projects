/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:40:17 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/09 19:40:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_puthex_justify_right(char *string,
	t_conversion *conversion, char fill, t_format *format)
{
	size_t			length;
	size_t			i;

	i = 0;
	length = ((unsigned int)ft_strlen(string) < conversion->precision) ?
				conversion->precision : (unsigned int)ft_strlen(string);
	if (conversion->precision_set && conversion->specifier != POINTER)
		fill = ' ';
	add_width_spaces(fill, length, format, conversion);
	if (string[i] != '\0')
		if (conversion->flags.hashtag)
			i = zeroxprint(string, format, conversion);
	add_width_zeros(fill, length, format, conversion);
	if (string[i] != '\0')
		if (conversion->precision_set)
			precision_zeros(conversion, string, format, 2);
	while (string[i] != '\0')
	{
		ft_putchar(string[i]);
		i++;
		format->written++;
	}
}

void		ft_puthex_justify_left(char *string,
	t_conversion *conversion, char fill, t_format *format)
{
	size_t			i;

	i = 0;
	if (string[i] != '\0')
	{
		if (conversion->flags.hashtag)
			i = zeroxprint(string, format, conversion);
		if (conversion->precision_set)
			precision_zeros(conversion, string, format, 2);
	}
	while (string[i] != '\0')
	{
		ft_putchar(string[i]);
		i++;
		format->written++;
	}
	while (i < conversion->width)
	{
		ft_putchar(fill);
		i++;
		format->written++;
	}
}

static int	convert_decimal_to_hex(int rem, t_conversion *conversion)
{
	if (rem == 10)
		return (conversion->specifier == HEX_UPPER ? 'A' : 'a');
	else if (rem == 11)
		return (conversion->specifier == HEX_UPPER ? 'B' : 'b');
	else if (rem == 12)
		return (conversion->specifier == HEX_UPPER ? 'C' : 'c');
	else if (rem == 13)
		return (conversion->specifier == HEX_UPPER ? 'D' : 'd');
	else if (rem == 14)
		return (conversion->specifier == HEX_UPPER ? 'E' : 'e');
	else if (rem == 15)
		return (conversion->specifier == HEX_UPPER ? 'F' : 'f');
	else
		return (rem + '0');
}

static void	continue_decimal_to_hex(size_t n, t_format *format,
	t_conversion *conversion, char *hex_str)
{
	char	fill;
	size_t	i;

	i = 0;
	if (conversion->flags.pad_with_zeros)
		fill = '0';
	else
		fill = ' ';
	while (n != 0)
	{
		hex_str[i] = convert_decimal_to_hex(n % 16, conversion);
		++i;
		n /= 16;
	}
	if (conversion->flags.hashtag)
	{
		hex_str[i++] = (conversion->specifier == HEX_UPPER ? 'X' : 'x');
		hex_str[i++] = '0';
	}
	hex_str[i] = '\0';
	ft_strrev(hex_str);
	if (conversion->flags.left_justify)
		ft_puthex_justify_left(hex_str, conversion, ' ', format);
	else
		ft_puthex_justify_right(hex_str, conversion, fill, format);
}

void		decimal_to_hex(size_t n, t_format *format, t_conversion *conversion)
{
	char	*hex_str;

	if (n == 0)
	{
		zerocasehex(conversion, format);
		return ;
	}
	if (conversion->length == HH)
		n = n % 256;
	if (conversion->flags.hashtag)
		hex_str = ft_memalloc(sizeof(char) * (ft_intpwr(n, 16) + 2 + 1));
	else
		hex_str = ft_memalloc(sizeof(char) * (ft_intpwr(n, 16) + 1));
	continue_decimal_to_hex(n, format, conversion, hex_str);
}
