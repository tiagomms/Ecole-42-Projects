/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 14:38:30 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/11 14:38:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		continue_signed_int(t_conversion *conversion,
									t_format *format, intmax_t number)
{
	int		neg;

	neg = 0;
	if (number < 0)
	{
		if (conversion->width && !conversion->flags.left_justify &&
				!conversion->flags.pad_with_zeros)
		{
			number = number * -1;
			format->written++;
			neg = 1;
		}
		else
		{
			ft_putchar('-');
			number = number * -1;
			format->written++;
		}
		conversion->is_negative = 1;
	}
	if (conversion->flags.left_justify)
		ft_putnbr_justify_left(number, conversion, format);
	else
		ft_putnbr_justify_right(number, conversion, neg, format);
}

static void		signed_int(t_conversion *conversion, va_list arguments,
							t_format *format)
{
	intmax_t	number;

	if (conversion->length == HH)
	{
		ft_putnbr_intmax((signed char)va_arg(arguments, int), format,
									conversion);
		return ;
	}
	else if (conversion->length == H)
		number = va_arg(arguments, int);
	else if (conversion->length == L)
		number = va_arg(arguments, long);
	else if (conversion->length == LL)
		number = va_arg(arguments, long long);
	else if (conversion->length == J)
		number = va_arg(arguments, intmax_t);
	else if (conversion->length == Z)
		number = va_arg(arguments, size_t);
	else
		number = va_arg(arguments, int);
	continue_signed_int(conversion, format, number);
}

static void		unsigned_int(t_conversion *conversion, va_list arguments,
								t_format *format)
{
	uintmax_t	number;

	if (conversion->length == HH)
	{
		ft_putnbr_intmax((unsigned char)va_arg(arguments, int), format,
							conversion);
		return ;
	}
	else if (conversion->length == H)
		number = (unsigned short int)va_arg(arguments, int);
	else if (conversion->length == L)
		number = va_arg(arguments, unsigned long int);
	else if (conversion->length == LL)
		number = va_arg(arguments, unsigned long long int);
	else if (conversion->length == J)
		number = va_arg(arguments, uintmax_t);
	else if (conversion->length == Z)
		number = va_arg(arguments, size_t);
	else
		number = va_arg(arguments, unsigned int);
	if (conversion->flags.left_justify)
		ft_putnbr_justify_left(number, conversion, format);
	else
		ft_putnbr_justify_right(number, conversion, 0, format);
}

void			print_type_decimal(t_format *format, t_conversion *conversion,
								va_list arguments)
{
	if (conversion->specifier == S_DECIMAL)
		signed_int(conversion, arguments, format);
	if (conversion->specifier == U_DECIMAL)
		unsigned_int(conversion, arguments, format);
}
