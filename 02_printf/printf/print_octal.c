/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:42 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/09 19:39:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putoctal_justify_right(char *string,
					t_conversion *conversion, char fill, t_format *format)
{
	size_t			length;
	size_t			i;
	int				n;

	n = 0;
	i = 0;
	length = ((unsigned int)ft_strlen(string) < conversion->precision) ?
					conversion->precision : (unsigned int)ft_strlen(string);
	while (i + length < conversion->width)
	{
		ft_putchar(fill);
		i++;
		format->written++;
	}
	i = 0;
	while (string[i] != '\0')
	{
		if (conversion->precision_set && n == 0)
			precision_zeros(conversion, string, format, 0);
		n = 1;
		ft_putchar(string[i]);
		i++;
		format->written++;
	}
}

static void		ft_putoctal_justify_left(char *string,
					t_conversion *conversion, char fill, t_format *format)
{
	size_t			i;
	int				n;

	n = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (conversion->precision_set && n == 0)
			precision_zeros(conversion, string, format, 0);
		n = 1;
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

static int		null_case_octal(size_t n, t_format *format,
	t_conversion *conversion)
{
	if (n == 0)
	{
		if (!conversion->flags.hashtag && conversion->precision_set
			&& conversion->precision == 0)
			return (1);
		ft_putchar('0');
		format->written++;
		return (1);
	}
	return (0);
}

static size_t	convert_2accurate_octal(size_t *n, t_conversion *conversion)
{
	if (conversion->length == H)
		*n = *n % 65536;
	if (conversion->length == HH)
		*n = *n % 256;
	if (!conversion->length)
		*n = *n % 4294967296;
	return (0);
}

void			decimal_to_octal(size_t n, t_format *format,
	t_conversion *conversion)
{
	size_t	i;
	int		rem;
	char	*octal_str;

	if (null_case_octal(n, format, conversion))
		return ;
	i = convert_2accurate_octal(&n, conversion);
	if (conversion->flags.hashtag)
		octal_str = ft_memalloc(sizeof(char) * (ft_intpwr(n, 8) + 1 + 1));
	else
		octal_str = ft_memalloc(sizeof(char) * (ft_intpwr(n, 8) + 1));
	while (n != 0)
	{
		rem = n % 8;
		octal_str[i++] = rem + '0';
		n /= 8;
	}
	if (conversion->flags.hashtag)
		octal_str[i++] = '0';
	octal_str[i] = '\0';
	ft_strrev(octal_str);
	if (conversion->flags.left_justify)
		ft_putoctal_justify_left(octal_str, conversion, ' ', format);
	else
		ft_putoctal_justify_right(octal_str, conversion, ' ', format);
}
