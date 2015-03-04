/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:10:57 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/03 16:10:59 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_other5(t_parameters *parameters, int col, int line)
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
		xtemp = (exp(x) * cos(y)) + parameters->info->current_point[0];
		y = (exp(x) * sin(y)) + parameters->info->current_point[1];
		x = xtemp;
		if (((x * x) + (y * y)) > (2 * 2))
			break ;
		iteration++;
	}
	colours((double)iteration, parameters, col, line);
}

void	handle_other5(t_parameters *parameters)
{
	int line;
	int col;

	line = 0;
	while (line < parameters->screen->window_size[0])
	{
		col = 0;
		while (col < parameters->screen->window_size[1])
		{
			do_other5(parameters, col, line);
			col++;
		}
		line++;
	}
}
