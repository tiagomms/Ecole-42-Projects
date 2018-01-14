/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:03:39 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/02 17:03:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_mandelbrot(t_parameters *parameters, int col, int line)
{
	double	y0;
	double	x;
	double	y;
	double	xtemp;
	int		iteration;

	y0 = parameters->info->current_point[1];
	x = 0;
	y = 0;
	iteration = 0;
	while (((x * x) + (y * y)) < (2 * 2)
			&& iteration < parameters->info->max_iterations)
	{
		xtemp = (x * x) - (y * y) + parameters->info->current_point[0];
		y = (2 * x * y) + y0;
		x = xtemp;
		if (((x * x) + (y * y)) > (2 * 2))
			break ;
		iteration++;
	}
	colours((double)iteration, parameters, col, line);
}

void	handle_mandelbrot(t_parameters *parameters)
{
	int	line;
	int	col;

	line = 0;
	while (line < parameters->screen->window_size[0])
	{
		col = 0;
		while (col < parameters->screen->window_size[1])
		{
			parameters->info->current_point[0] =
			get_current_x0(parameters, col);
			parameters->info->current_point[1] =
			get_current_y0(parameters, line);
			do_mandelbrot(parameters, col, line);
			col++;
		}
		line++;
	}
}
