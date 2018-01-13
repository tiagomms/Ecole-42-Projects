/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_with_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 19:41:32 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/05 19:41:34 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		deal_with_precision(t_format *format, t_conversion *conversion)
{
	if (format->string[format->location] == '.')
	{
		conversion->precision_set = 1;
		format->location++;
		conversion->precision = custom_atoi(format);
	}
}
