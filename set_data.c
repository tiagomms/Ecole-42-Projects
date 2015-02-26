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
	screen->window = mlx_new_window(screen->mlx_ptr, screen->window_size[0],
								screen->window_size[1], "Fractol");
	screen->image_ptr = mlx_new_image(screen->mlx_ptr, screen->window_size[0],
								screen->window_size[1]);
	screen->image_data = (unsigned int*)mlx_get_data_addr(screen->image_ptr,
							&screen->bits_per_pixel, &screen->size_line,
							&screen->endian);
	screen->endian = 1;
	screen->size_line /= 4;
}

void	set_new_info(t_info *info, t_screen *screen)
{
	double focus;

	focus = 2.5 / info->zoom;
	info->current_limits_x[0] = info->central_point[0] - focus;
	info->current_limits_x[1] = info->central_point[0] + focus;
	info->current_limits_y[0] = info->central_point[1] - focus;
	info->current_limits_y[1] = info->central_point[1] + focus;
	info->x_gradient = (info->current_limits_x[1] - info->current_limits_x[0]) /
						screen->window_size[0];
	info->y_gradient = (info->current_limits_y[1] - info->current_limits_y[0]) /
						screen->window_size[1];
}

void	set_info(t_info *info, t_screen *screen)
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
	info->x_gradient = (info->current_limits_x[1] - info->current_limits_x[0]) /
						screen->window_size[0];
	info->y_gradient = (info->current_limits_y[1] - info->current_limits_y[0]) /
						screen->window_size[1];
	info->colour_gradient = (255.0 / info->max_iterations);
}
