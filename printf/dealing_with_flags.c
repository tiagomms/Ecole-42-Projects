/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_with_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:41:29 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:35:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	con_check_flags(t_format *format, t_conversion *conversion)
{
	if (format->string[format->location] == '0')
	{
		if (!conversion->flags.left_justify)
			conversion->flags.pad_with_zeros = 1;
		return (1);
	}
	else if (format->string[format->location] == '#')
	{
		conversion->flags.hashtag = 1;
		return (1);
	}
	return (0);
}

static t_bool	check_flags(t_format *format, t_conversion *conversion)
{
	if (format->string[format->location] == '+')
	{
		conversion->flags.show_sign = 1;
		conversion->flags.positive_values_begin_blank = 0;
		return (1);
	}
	else if (format->string[format->location] == ' ')
	{
		if (!conversion->flags.show_sign)
			conversion->flags.positive_values_begin_blank = 1;
		return (1);
	}
	else if (format->string[format->location] == '-')
	{
		conversion->flags.left_justify = 1;
		conversion->flags.pad_with_zeros = 0;
		return (1);
	}
	return (con_check_flags(format, conversion));
}

void			deal_with_flags(t_format *format, t_conversion *conversion)
{
	while (check_flags(format, conversion))
	{
		format->location++;
	}
}
