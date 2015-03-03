/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:54:11 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/25 17:54:18 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_screen(t_screen *screen)
{
	screen->mlx_ptr = mlx_init();
	screen->window_size[0] = 1000;
	screen->window_size[1] = 1000;
	screen->window = mlx_new_window(screen->mlx_ptr, 1420,
								screen->window_size[1], "Fractol");
	screen->image_ptr = mlx_new_image(screen->mlx_ptr, screen->window_size[0] ,
								screen->window_size[1]);
	screen->image_data = (unsigned int*)mlx_get_data_addr(screen->image_ptr,
							&screen->bits_per_pixel, &screen->size_line,
							&screen->endian);
	screen->endian = 1;
	screen->size_line /= 4;
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 100, 0xFFFFFF,"Menu of Options:");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 120, 0xFFFFFF,"Mouse click    change central point");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 140, 0xFFFFFF,"Scroll wheel   zoom in/out");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 160, 0xFFFFFF,"b              palette - black/white");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 180, 0xFFFFFF,"m              palette - fixed green");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 200, 0xFFFFFF,"n              palette - varied");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 220, 0xFFFFFF,"q              increase hue");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 240, 0xFFFFFF,"w              decrease hue");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 260, 0xFFFFFF,"l              julia - activate lock");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 280, 0xFFFFFF,"u              julia - deactivate lock");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 300, 0xFFFFFF,"up arrow       move central point up");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 320, 0xFFFFFF,"down arrow     move central point down");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 340, 0xFFFFFF,"left arrow     move central point left");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 360, 0xFFFFFF,"right arrow    move central point right");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 380, 0xFFFFFF,"r              reset current fractal");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 400, 0xFFFFFF,"ESC key        quit");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 500, 0xFFFFFF,"Fractol options");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 520, 0xFFFFFF,"1              julia");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 540, 0xFFFFFF,"2              mandelbrot");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 560, 0xFFFFFF,"3              burning");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 580, 0xFFFFFF,"4              other1");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 600, 0xFFFFFF,"5              other2");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 620, 0xFFFFFF,"6              other3");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 640, 0xFFFFFF,"7              nova");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 660, 0xFFFFFF,"8              other4");
	mlx_string_put(screen->mlx_ptr, screen->window, 1100, 680, 0xFFFFFF,"9              other5");
}

void	set_new_info(t_info *info, t_screen *screen)
{
	double focus;

	focus = 2.5 / info->zoom;
	if (focus <= 0.000000000001f)
	{
		focus = 0.000000000001f;
		info->zoom = 2.5 / focus;
	}
	info->current_limits_x[0] = info->central_point[0] - focus;
	info->current_limits_x[1] = info->central_point[0] + focus;
	info->current_limits_y[0] = info->central_point[1] - focus;
	info->current_limits_y[1] = info->central_point[1] + focus;
	info->epsilon = (info->current_limits_x[1] - info->current_limits_x[0]) /
						screen->window_size[0];
}

void	set_info(t_info *info, t_screen *screen, t_parameters *parameters)
{
	info->central_point[0] = 0.0;
	info->central_point[1] = 0.0;
	info->current_limits_x[0] = -2.5;
	info->current_limits_x[1] = 2.5;
	info->current_limits_y[0] = -2.5;
	info->current_limits_y[1] = 2.5;
	info->current_point[0] = info->current_limits_x[0];
	info->current_point[1] = info->current_limits_y[1];
	info->zoom = 1;
	parameters->background_hue = 255;
	parameters->lock_activated = 0;
	parameters->relaxation_c = 2;
	parameters->palette = RGB;
	info->epsilon = (info->current_limits_x[1] - info->current_limits_x[0]) /
						screen->window_size[0];
	info->colour_gradient = (255.0 / info->max_iterations);
}
