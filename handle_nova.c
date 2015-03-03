/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nova.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:10:50 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/03 16:10:52 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_nova(t_parameters *parameters, int col, int line)
{
	double	constant;
	double	x;
	double	y;
	double	xtemp;
	int		iteration;

	constant = (parameters->relaxation_const / (3 * ((x * x + y * y) * (x * x + y * y))));
	x = get_current_x0(parameters, col);
	y = get_current_y0(parameters, line);
	iteration = 0;
	while (iteration < parameters->info->max_iterations)
	{
		xtemp = parameters->info->current_point[0] + x + constant * ((x * x) -
			(y * y) - (x * y * y * y * y) - (x * x * x * x * x) -
			(2 * x * x * x * y * y));
		y = parameters->info->current_point[1] + y - constant * y * 
		((2 * x) + (y * y * y * y) + (2 * x * x * y * y) + (x * x * x * x));
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
