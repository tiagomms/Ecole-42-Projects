/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:05:33 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/26 11:05:41 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_current_x0(t_parameters *parameters, int col)
{
	double result;

	result = parameters->info->current_limits_x[0] +
				(col * parameters->info->x_gradient);
	return (result);
}

double	get_current_y0(t_parameters *parameters, int line)
{
	double result;

	result = parameters->info->current_limits_y[1] -
				(line * parameters->info->y_gradient);
	return (result);
}

int		color_in_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + (b));
}

void	colours(double iteration, t_parameters *parameters, int col, int line)
{
	int	current_rgb;

	current_rgb = (int)floor(iteration * parameters->info->colour_gradient);
	parameters->screen->image_data[line * parameters->screen->window_size[0] 
		+ col] = color_in_int(current_rgb, current_rgb, current_rgb);
}

void	do_mandelbrot(t_parameters *parameters, int col, int line)
{
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	xtemp;
	int		iteration;

	x0 = parameters->info->current_point[0];
	y0 = parameters->info->current_point[1];
	x = 0;
	y = 0;
	iteration = 0;
	while (((x * x) + (y * y)) < (2 * 2)
			&& iteration < parameters->info->max_iterations)
	{
		xtemp = (x * x) - (y * y) + x0;
		y = (2 * x * y) + y0;
		x = xtemp;
		if (((x * x) + (y * y)) > (2 * 2))
			break ;
		iteration++;
	}
	colours((double)iteration, parameters, col, line);
	//smoothing
}

void	handle_fractol(t_parameters *parameters)
{
	int	line;
	int	col;

	line = 0;
	while (line < parameters->screen->window_size[0])
	{
		col = 0;
		while (col < parameters->screen->window_size[1])
		{
			parameters->info->current_point[0] = get_current_x0(parameters, col);
			parameters->info->current_point[1] = get_current_y0(parameters, line);
			if (parameters->fractype == MANDELBROT)
				do_mandelbrot(parameters, col, line);
			col++;
		}
		line++;
	}
}