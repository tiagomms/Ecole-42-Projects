/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:18:09 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/14 16:32:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <wchar.h>

int					ft_printf(char const *format, ...);

typedef char		t_bool;

typedef struct		s_format
{
	const char		*string;
	size_t			location;
	size_t			written;
}					t_format;

typedef struct		s_flags
{
	t_bool			left_justify;
	t_bool			pad_with_zeros;
	t_bool			show_sign;
	t_bool			positive_values_begin_blank;
	t_bool			hashtag;
}					t_flags;

/*
** sorted by size (generally speaking)
** DEFAULT_LENGTH because bzero at beginning has to make new conversion
*/

typedef enum		e_length
{
	DEFAULT_LENGTH, HH, H, L, LL, J, Z
}					t_length;

/*
** see parse_specifier for more specifier table
*/

typedef enum		e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING,
	POINTER, INVALID_SPECIFIER, NOTHING
}					t_specifier;

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	t_bool			precision_set;
	t_length		length;
	t_specifier		specifier;
	t_bool			is_negative;
}					t_conversion;

void				deal_with_flags(t_format *format, t_conversion *conversion);
void				deal_with_width(t_format *format, t_conversion *conversion);
unsigned int		custom_atoi(t_format *format);
void				deal_with_precision(t_format *format,
									t_conversion *conversion);
void				deal_with_length(t_format *format,
										t_conversion *conversion);
void				deal_with_specifier(t_format *format,
										t_conversion *conversion);
void				ft_putnbr_intmax(intmax_t n, t_format *format,
										t_conversion *conversion);
void				ft_putnbr_sizet(size_t n, t_format *format,
										t_conversion *conversion);
void				ft_putnbr_shortint(short int n, t_format *format,
										t_conversion *conversion);
void				print_normal_string(char *s, t_format *format,
										t_conversion *conversion);
void				print_type_decimal(t_format *format,
						t_conversion *conversion, va_list arguments);
void				print_type_char(va_list arguments, t_format *format,
									t_conversion *conversion);
void				decimal_to_hex(size_t n, t_format *format,
								t_conversion *conversion);
void				precision_zeros(t_conversion *conversion, char *string,
									t_format *format, int i);
void				decimal_to_octal(size_t n, t_format *format,
								t_conversion *conversion);
int					ft_intpwr(size_t n, int base);
void				print_wide_string(t_conversion *conversion,
									wchar_t *wstring, t_format *format);
void				print_type_string(va_list arguments, t_format *format,
									t_conversion *conversion);
void				ft_putnbr_justify_left(uintmax_t number,
									t_conversion *conversion, t_format *format);
void				ft_putnbr_justify_right(uintmax_t number,
						t_conversion *conversion, int neg, t_format *format);
char				*ft_itoa_uintmax(uintmax_t n);
unsigned int		limit_wchart_print_bytes(wchar_t *wstring,
	t_conversion *conversion);
void				count_wint_bytes(unsigned int *count, wint_t wint);
void				print_wint(wint_t wint, size_t *written);
void				add_width_zeros(char fill, size_t length,
								t_format *format, t_conversion *conversion);
void				add_width_spaces(char fill, size_t length,
							t_format *format, t_conversion *conversion);
void				zerocasehex(t_conversion *conversion, t_format *format);
int					zeroxprint(char *string, t_format *format,
						t_conversion *conversion);
void				ft_puthex_justify_right(char *string,
					t_conversion *conversion, char fill, t_format *format);
void				ft_puthex_justify_left(char	*string,
					t_conversion *conversion, char fill, t_format *format);

#endif
