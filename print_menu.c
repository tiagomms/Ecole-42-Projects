/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:21:11 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/04 10:21:13 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	continue_continuing_print_menu(t_screen *screen)
{
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 540, 0xFFFFFF,
					"Fractol options:");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 560, 0xFFFFFF,
					"1              julia");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 580, 0xFFFFFF,
					"2              mandelbrot");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 600, 0xFFFFFF,
					"3              burning");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 620, 0xFFFFFF,
					"4              other1");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 640, 0xFFFFFF,
					"5              other2");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 660, 0xFFFFFF,
					"6              other3");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 680, 0xFFFFFF,
					"7              nova");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 700, 0xFFFFFF,
					"8              other4");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 720, 0xFFFFFF,
					"9              other5");
}

static void	continue_print_menu(t_screen *screen)
{
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 340, 0xFFFFFF,
					"up arrow       move central point up");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 360, 0xFFFFFF,
					"down arrow     move central point down");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 380, 0xFFFFFF,
					"left arrow     move central point left");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 400, 0xFFFFFF,
					"right arrow    move central point right");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 420, 0xFFFFFF,
					"r              reset current fractal");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 440, 0xFFFFFF,
					"ESC key        quit");
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
	continue_continuing_print_menu(screen);
}

void	print_menu(t_screen *screen)
{
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 100, 0xFFFFFF,
					"Menu of Options:");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 120, 0xFFFFFF,
					"Mouse click    change central point");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 140, 0xFFFFFF,
					"Scroll wheel   zoom in/out");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 160, 0xFFFFFF,
					"b              palette - black/white");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 180, 0xFFFFFF,
					"m              palette - fixed green");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 200, 0xFFFFFF,
					"n              palette - varied");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 220, 0xFFFFFF,
					"q              increase hue");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 240, 0xFFFFFF,
					"w              decrease hue");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 260, 0xFFFFFF,
					"l              julia - activate lock");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 280, 0xFFFFFF,
					"u              julia - deactivate lock");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 300, 0xFFFFFF,
					"z              nova - increase R (until 6)");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 320, 0xFFFFFF,
					"x              nova - decrease R (until 1)");
	continue_print_menu(screen);
}
