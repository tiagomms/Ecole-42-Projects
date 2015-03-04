/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:02:57 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/04 11:03:07 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_uintipwr(uintmax_t n)
{
	return (n < 10 ? 1 : 1 + ft_uintipwr(n / 10));
}

static char		*ft_uintchr(char *s, uintmax_t n, size_t lim, size_t p)
{
	if (lim == p)
		return (s);
	s[p - 1] = (n % 10) + 48;
	return (ft_uintchr(s, n / 10, lim, p - 1));
}

char			*ft_itoa_uintmax(uintmax_t n)
{
	char	*s;
	int		p;

	p = ft_uintipwr(n);
	if (!(s = (char*)malloc(sizeof(char) * (p + 1))))
		return (NULL);
	s[p] = '\0';
	return (ft_uintchr(s, n, 0, p));
}

char	*ft_ftoa(double n, int precision)
{
	double	rest;
	char	*str_number;
	int		i;
	double	abs_n;

	i = 0;
	abs_n = ft_abs_double(n);
	str_number = ft_itoa_uintmax((uintmax_t)floor(abs_n));
	rest = abs_n - floor(abs_n);
	str_number = ft_strjoin(str_number, ".");
	while (i < precision && floor(rest * 10) == 0.0)
	{
		rest *= 10;
		str_number = ft_strjoin(str_number, "0");
		i++;
	}
	while (i < precision)
	{
		rest *= 10;
		i++;
	}
	if ((((uintmax_t)floor(rest * 10)) % 10) > 5)
		rest = ceil(rest);
	else
		rest = floor(rest);
	str_number = ft_strjoin(str_number, ft_itoa_uintmax((uintmax_t)rest));
	if (n < 0)
		str_number = ft_strjoin("-", str_number);
	else
		str_number = ft_strjoin(" ", str_number);
	return (str_number);
}

void	clear_pixels(t_screen *screen)
{
	int x;
	int y;

	x = 1220;
	while (x < 1400)
	{
		y = 820;
		while (y < 920)
		{
			mlx_pixel_put(screen->mlx_ptr, screen->window, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	print_display(t_parameters *parameters, t_screen *screen)
{
	clear_pixels(screen);
	if (if_julia_and_others(parameters))
	{
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 860, 0xFFFFFF,
			ft_ftoa(parameters->info->current_point[0], 13));
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 880, 0xFFFFFF,
			ft_ftoa(parameters->info->current_point[1], 13));		
	}
	else
	{
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 860, 0xFFFFFF,
			ft_ftoa(parameters->info->central_point[0], 13));
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 880, 0xFFFFFF,
			ft_ftoa(parameters->info->central_point[1], 13));	
	}
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 900, 0xFFFFFF,
			ft_ftoa((parameters->info->initial_axis_length / parameters->info->zoom), 13));
	if (parameters->fractype == JULIA)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"julia");
	else if (parameters->fractype == MANDELBROT)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"mandelbrot");
	else if (parameters->fractype == BURNING)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"burning");
	else if (parameters->fractype == OTHER1)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"other1");
	else if (parameters->fractype == OTHER2)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"other2");
	else if (parameters->fractype == OTHER3)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"other3");
	else if (parameters->fractype == NOVA)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"nova");
	else if (parameters->fractype == OTHER4)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"other4");
	else if (parameters->fractype == OTHER5)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"other5");
}
