/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_wint_bytes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:29:21 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/12 14:29:22 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			count_wint_bytes(unsigned int *count, wint_t wint)
{
	if (wint <= 0x7F)
		*count += 1;
	else if (wint <= 0x7FF)
		*count += 2;
	else if (wint <= 0xFFFF)
		*count += 3;
	else if (wint <= 0x10FFFF)
		*count += 4;
}

static void		subtract_wint_bytes(unsigned int *count, wint_t wint)
{
	if (wint <= 0x7F)
		*count -= 1;
	else if (wint <= 0x7FF)
		*count -= 2;
	else if (wint <= 0xFFFF)
		*count -= 3;
	else if (wint <= 0x10FFFF)
		*count -= 4;
}

unsigned int	limit_wchart_print_bytes(wchar_t *wstring,
	t_conversion *conversion)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (wstring[i])
	{
		count_wint_bytes(&count, wstring[i]);
		if (conversion->precision_set)
		{
			if (count > conversion->precision)
			{
				subtract_wint_bytes(&count, wstring[i]);
				break ;
			}
		}
		i++;
	}
	return (count);
}
