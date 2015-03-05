/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:56:33 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:30:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][specifier]type
*/

void		print_args(t_format *format, t_conversion *conversion,
							va_list arguments)
{
	if (conversion->specifier == S_DECIMAL)
		print_type_decimal(format, conversion, arguments);
	else if (conversion->specifier == U_DECIMAL)
		print_type_decimal(format, conversion, arguments);
	else if (conversion->specifier == STRING)
		print_type_string(arguments, format, conversion);
	else if (conversion->specifier == CHAR)
		print_type_char(arguments, format, conversion);
	else if (conversion->specifier == HEX_LOWER ||
					conversion->specifier == HEX_UPPER)
		decimal_to_hex(va_arg(arguments, size_t), format, conversion);
	else if (conversion->specifier == OCTAL)
		decimal_to_octal(va_arg(arguments, size_t), format, conversion);
	else if (conversion->specifier == POINTER)
	{
		conversion->flags.hashtag = 1;
		decimal_to_hex(va_arg(arguments, size_t), format, conversion);
	}
}

void		readformat(t_format *format, va_list arguments)
{
	t_conversion	conversion;

	ft_bzero(&conversion, sizeof(conversion));
	deal_with_flags(format, &conversion);
	deal_with_width(format, &conversion);
	deal_with_precision(format, &conversion);
	deal_with_length(format, &conversion);
	deal_with_specifier(format, &conversion);
	if (conversion.specifier == NOTHING)
		return ;
	print_args(format, &conversion, arguments);
}

void		handle_format(t_format *format, va_list arguments)
{
	while (format->string[format->location])
	{
		if (format->string[format->location] == '%')
		{
			format->location++;
			readformat(format, arguments);
		}
		else
		{
			ft_putchar(format->string[format->location]);
			format->written++;
			format->location++;
		}
	}
}

int			ft_printf(char const *string, ...)
{
	va_list		arguments;
	t_format	format;

	ft_bzero(&format, sizeof(format));
	format.string = string;
	va_start(arguments, string);
	handle_format(&format, arguments);
	va_end(arguments);
	return (format.written);
}
