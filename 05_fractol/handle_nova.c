/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nova.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:24:11 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/04 10:24:13 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_nova(t_parameters *parameters, int col, int line)
{
	double	x;
	double	y;
	double	xtemp;
	int		iteration;

	x = get_current_x0(parameters, col);
	y = get_current_y0(parameters, line);
	iteration = 0;
	while (iteration < parameters->info->max_iterations)
	{
		xtemp = parameters->info->current_point[0] + x +
		(parameters->relaxation_c / (3 * ((x * x + y * y) *
		(x * x + y * y))))
		* ((x * x) - (y * y) - (x * y * y * y * y) - (x * x * x * x * x) -
		(2 * x * x * x * y * y));
		y = parameters->info->current_point[1] + y -
		(parameters->relaxation_c / (3 * ((x * x + y * y) * (x * x + y * y))))
		* y * ((2 * x) + (y * y * y * y) + (2 * x * x * y * y) +
		(x * x * x * x));
		x = xtemp;
		if (((x * x) + (y * y)) > (2 * 2))
			break ;
		iteration++;
	}
	colours((double)iteration, parameters, col, line);
}

void	handle_nova(t_parameters *parameters)
{
	int line;
	int col;

	line = 0;
	if (parameters->relaxation_c == 0)
		parameters->relaxation_c = 2;
	while (line < parameters->screen->window_size[0])
	{
		col = 0;
		while (col < parameters->screen->window_size[1])
		{
			do_nova(parameters, col, line);
			col++;
		}
		line++;
	}
}
