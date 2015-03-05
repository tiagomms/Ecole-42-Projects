/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:09:59 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/09 14:10:02 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		continue_putstr_right(char *string, t_conversion *conversion,
										t_format *format)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (conversion->precision_set)
			if (i == conversion->precision &&
					conversion->specifier != INVALID_SPECIFIER)
				break ;
		ft_putchar(string[i]);
		i++;
		format->written++;
	}
}

static void		ft_putstr_justify_right(char *string, t_conversion *conversion,
										char fill, t_format *format)
{
	size_t			length;
	size_t			i;

	if (conversion->precision_set && conversion->precision <
		(unsigned int)ft_strlen(string) &&
		conversion->specifier != INVALID_SPECIFIER)
		length = conversion->precision;
	else
		length = ft_strlen(string);
	i = 0;
	while (i + length < conversion->width)
	{
		ft_putchar(fill);
		i++;
		format->written++;
	}
	continue_putstr_right(string, conversion, format);
}

static void		ft_putstr_justify_left(char *string,
					t_conversion *conversion, char fill, t_format *format)
{
	size_t			i;

	i = 0;
	while (string[i] != '\0')
	{
		if (conversion->precision_set &&
					conversion->specifier != INVALID_SPECIFIER)
			if (i == conversion->precision)
				break ;
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

void			print_normal_string(char *s, t_format *format,
	t_conversion *conversion)
{
	char	c;

	if (conversion->flags.pad_with_zeros)
		c = '0';
	else
		c = ' ';
	if (!s)
		s = ft_strdup("(null)");
	if (conversion->flags.left_justify)
		ft_putstr_justify_left(s, conversion, c, format);
	else
		ft_putstr_justify_right(s, conversion, c, format);
}
