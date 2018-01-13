/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_with_specifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:39:35 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:36:21 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_current(t_format *format, int c)
{
	return (format->string[format->location] == c);
}

static void		deal_with_capitals(t_format *format, t_conversion *conversion)
{
	if (is_current(format, 'D') ||
		is_current(format, 'C') ||
		is_current(format, 'S') ||
		is_current(format, 'O') ||
		is_current(format, 'U'))
		conversion->length = L;
}

static t_bool	is_invalid_specifier(t_format *format)
{
	int chr;

	chr = format->string[format->location];
	if (ft_isprint(chr))
		if (!ft_isdigit(chr) && chr != '.' && chr != '#' && chr != '+'
			&& chr != '-' && chr != ' ')
			return (1);
	return (0);
}

static t_bool	valid_specifier_case(t_format *format,
							t_conversion *conversion)
{
	if (is_current(format, 'd') ||
		is_current(format, 'D') ||
		is_current(format, 'i'))
		conversion->specifier = S_DECIMAL;
	else if (is_current(format, 'u') || is_current(format, 'U'))
		conversion->specifier = U_DECIMAL;
	else if (is_current(format, 'o') || is_current(format, 'O'))
		conversion->specifier = OCTAL;
	else if (is_current(format, 'x'))
		conversion->specifier = HEX_LOWER;
	else if (is_current(format, 'X'))
		conversion->specifier = HEX_UPPER;
	else if (is_current(format, 'c') || is_current(format, 'C'))
		conversion->specifier = CHAR;
	else if (is_current(format, 's') || is_current(format, 'S'))
		conversion->specifier = STRING;
	else if (is_current(format, 'p'))
		conversion->specifier = POINTER;
	else
		return (0);
	return (1);
}

void			deal_with_specifier(t_format *format, t_conversion *conversion)
{
	char	*invalid_case_char;

	if (valid_specifier_case(format, conversion))
	{
		deal_with_capitals(format, conversion);
		format->location++;
		return ;
	}
	else if (is_invalid_specifier(format))
	{
		conversion->specifier = INVALID_SPECIFIER;
		invalid_case_char = (char*)ft_memset(ft_memalloc(1),
							format->string[format->location], 1);
		print_normal_string(invalid_case_char, format, conversion);
	}
	else
	{
		conversion->specifier = NOTHING;
		return ;
	}
	format->location++;
}
