/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_with_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:08:56 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:35:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	con_deal_with_length(t_format *format, t_conversion *conversion)
{
	if (format->string[format->location] == 'j')
		conversion->length = J;
	else if (format->string[format->location] == 'z')
		conversion->length = Z;
	if (!conversion->length)
		conversion->length = DEFAULT_LENGTH;
	else
		format->location++;
}

void		deal_with_length(t_format *format, t_conversion *conversion)
{
	if (format->string[format->location] == 'h')
	{
		if (format->string[format->location + 1] == 'h')
		{
			conversion->length = HH;
			format->location++;
		}
		else
			conversion->length = H;
	}
	else if (format->string[format->location] == 'l')
	{
		if (format->string[format->location + 1] == 'l')
		{
			conversion->length = LL;
			format->location++;
		}
		else
			conversion->length = L;
	}
	con_deal_with_length(format, conversion);
}
