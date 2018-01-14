/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:10:40 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/03 16:10:41 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_other3(t_parameters *parameters, int col, int line)
{
	double	y0;
	double	x;
	double	y;
	double	xtemp;
	int		iteration;

	y0 = parameters->info->current_point[1];
	x = get_current_x0(parameters, col);
	y = get_current_y0(parameters, line);
	iteration = 0;
	while (iteration < parameters->info->max_iterations)
	{
		xtemp = parameters->info->current_point[0] + ((x * x - y * y) *
				(1 + (1 / (10 * ((x * x + y * y) * (x * x + y * y))))));
		y = (2 * x * y) - ((x * y) / (5 * (x * x + y * y) * (x * x + y * y)))
		+ y0;
		x = xtemp;
		if (((x * x) + (y * y)) > (2 * 2))
			break ;
		iteration++;
	}
	colours((double)iteration, parameters, col, line);
}

void	handle_other3(t_parameters *parameters)
{
	int line;
	int col;

	line = 0;
	while (line < parameters->screen->window_size[0])
	{
		col = 0;
		while (col < parameters->screen->window_size[1])
		{
			do_other3(parameters, col, line);
			col++;
		}
		line++;
	}
}
