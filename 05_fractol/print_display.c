/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:02:57 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/05 14:53:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clear_pixels(t_screen *screen)
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

static void	continue_display_fractype(t_parameters *parameters,
										t_screen *screen)
{
	if (parameters->fractype == MANDELBROT)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840,
						0xFFFFFF, "mandelbrot");
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

void		print_display(t_parameters *parameters, t_screen *screen)
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
	ft_ftoa(parameters->info->initial_axis_length / parameters->info->zoom,
				13));
	if (parameters->fractype == JULIA)
		mlx_string_put(screen->mlx_ptr, screen->window, 1220, 840, 0xFFFFFF,
						"julia");
	else
		continue_display_fractype(parameters, screen);
}
