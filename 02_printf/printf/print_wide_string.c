/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:26:50 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/11 11:26:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putwidestr_justify_right(wchar_t *wstring,
						t_conversion *conversion, char fill, size_t *written)
{
	size_t			i;
	unsigned int	limit_of_bytes;

	limit_of_bytes = limit_wchart_print_bytes(wstring, conversion);
	i = 0;
	while (i + limit_of_bytes < conversion->width)
	{
		print_wint(fill, written);
		i++;
	}
	i = 0;
	limit_of_bytes = 0;
	while (wstring[i])
	{
		count_wint_bytes(&limit_of_bytes, wstring[i]);
		if (conversion->precision_set)
			if (limit_of_bytes > conversion->precision)
				break ;
		print_wint(wstring[i], written);
		i++;
	}
}

static void		ft_putwidestr_justify_left(wchar_t *wstring,
				t_conversion *conversion, char fill, size_t *written)
{
	int				i;
	unsigned int	limit_bts;
	unsigned int	count_bts;

	i = 0;
	limit_bts = limit_wchart_print_bytes(wstring, conversion);
	count_bts = 0;
	while (wstring[i])
	{
		count_wint_bytes(&count_bts, wstring[i]);
		if (conversion->precision_set)
			if (count_bts > limit_bts)
				break ;
		print_wint(wstring[i], written);
		i++;
	}
	while (limit_bts < conversion->width)
	{
		print_wint(fill, written);
		limit_bts++;
	}
}

void			print_wide_string(t_conversion *conversion, wchar_t *wstring,
									t_format *format)
{
	char			c;
	char			*null_case;

	if (conversion->flags.pad_with_zeros)
		c = '0';
	else
		c = ' ';
	if (!wstring)
	{
		null_case = ft_strdup("(null)");
		print_normal_string(null_case, format, conversion);
		return ;
	}
	if (conversion->flags.left_justify)
		ft_putwidestr_justify_left(wstring, conversion, c, &format->written);
	else
		ft_putwidestr_justify_right(wstring, conversion, c, &format->written);
}
