/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 09:24:46 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/10 09:24:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	case_flags_plus_space(t_format *format, t_conversion *conversion)
{
	if (!conversion->is_negative && conversion->specifier == S_DECIMAL)
	{
		if (conversion->flags.show_sign)
		{
			ft_putchar('+');
			format->written++;
		}
		else if (conversion->flags.positive_values_begin_blank)
		{
			ft_putchar(' ');
			format->written++;
		}
	}
}

static void	print_putnbr_after_width(t_format *format,
								t_conversion *conversion, char *string)
{
	size_t		i;

	i = 0;
	while (string[i] != '\0')
	{
		if (conversion->precision_set && i == 0)
			precision_zeros(conversion, string, format, 0);
		ft_putchar(string[i]);
		i++;
		format->written++;
	}
}

void		ft_putnbr_justify_right(uintmax_t number,
						t_conversion *conversion, int neg, t_format *format)
{
	size_t			length;
	char			*string;
	char			fill;

	if (number == 0 && conversion->precision_set && conversion->precision == 0)
		return ;
	if (conversion->flags.pad_with_zeros && !conversion->precision_set)
		fill = '0';
	else
		fill = ' ';
	string = ft_itoa_uintmax(number);
	length = ((unsigned int)ft_strlen(string) < conversion->precision) ?
				conversion->precision : (unsigned int)ft_strlen(string);
	if (conversion->is_negative)
		length += 1;
	if (conversion->flags.show_sign ||
				conversion->flags.positive_values_begin_blank)
		length += 1;
	add_width_spaces(fill, length, format, conversion);
	case_flags_plus_space(format, conversion);
	if (neg == 1)
		ft_putchar('-');
	add_width_zeros(fill, length, format, conversion);
	print_putnbr_after_width(format, conversion, string);
}

void		ft_putnbr_justify_left(uintmax_t number,
						t_conversion *conversion, t_format *format)
{
	size_t			i;
	char			*string;
	char			fill;

	fill = ' ';
	i = 0;
	if (number == 0 && conversion->precision_set && conversion->precision == 0)
		return ;
	string = ft_itoa_uintmax(number);
	case_flags_plus_space(format, conversion);
	while (string[i] != '\0')
	{
		if (conversion->precision_set && i == 0)
			precision_zeros(conversion, string, format, 0);
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
