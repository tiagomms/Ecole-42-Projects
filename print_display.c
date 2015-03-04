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
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 820, 0xFFFFFF,
		"Current Fractol Info");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 840, 0xFFFFFF,
		"Fractol:");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 860, 0xFFFFFF,
		"Central Point - x:");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 880, 0xFFFFFF,
		"Central Point - y:");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 900, 0xFFFFFF,
		"Focus:");
	clear_pixels(screen);
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
