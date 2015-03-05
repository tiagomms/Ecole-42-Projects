/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:54:11 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/05 14:52:05 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_central_point(t_parameters *parameters, int x, int y)
{
	parameters->info->central_point[0] = get_current_x0(parameters, x);
	parameters->info->central_point[1] = get_current_y0(parameters, y);
	set_new_info(parameters->info, parameters->screen);
}

void	set_screen(t_screen *screen)
{
	screen->mlx_ptr = mlx_init();
	screen->window_size[0] = 1000;
	screen->window_size[1] = 1000;
	screen->window = mlx_new_window(screen->mlx_ptr, 1420,
								screen->window_size[1], "Fractol");
	screen->image_ptr = mlx_new_image(screen->mlx_ptr, screen->window_size[0],
								screen->window_size[1]);
	screen->image_data = (unsigned int*)mlx_get_data_addr(screen->image_ptr,
							&screen->bits_per_pixel, &screen->size_line,
							&screen->endian);
	screen->endian = 1;
	screen->size_line /= 4;
	print_menu(screen);
}

void	set_new_info(t_info *info, t_screen *screen)
{
	double focus;

	focus = info->initial_axis_length / info->zoom;
	if (focus <= 0.000000000001f)
	{
		focus = 0.000000000001f;
		info->zoom = info->initial_axis_length / focus;
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
	parameters->relaxation_c = 0;
	if (parameters->fractype >= NOVA)
		parameters->info->initial_axis_length = 6;
	else
		info->initial_axis_length = 2.5;
	info->current_limits_x[0] = -info->initial_axis_length;
	info->current_limits_x[1] = info->initial_axis_length;
	info->current_limits_y[0] = -info->initial_axis_length;
	info->current_limits_y[1] = info->initial_axis_length;
	info->current_point[0] = info->current_limits_x[0];
	info->current_point[1] = info->current_limits_y[1];
	info->zoom = 1;
	parameters->background_hue = 255;
	parameters->lock_activated = 0;
	parameters->palette = RGB;
	info->epsilon = (info->current_limits_x[1] - info->current_limits_x[0]) /
						screen->window_size[0];
	info->colour_gradient = (255.0 / info->max_iterations);
}
