/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:05:37 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/02 14:05:38 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		colour_in_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + (b));
}

void	palette_fixed_colours(double iteration, t_parameters *parameters,
					int col, int line)
{
	double	current_hue;

	if (iteration == parameters->info->max_iterations)
	{
		parameters->screen->image_data[line * parameters->screen->window_size[0]
		+ col] = colour_in_int(0, 0, 0);
		return ;
	}
	current_hue = 112 - iteration * parameters->info->colour_gradient;
	if (current_hue < 0)
		current_hue += 360;
	hsb_to_rgb(current_hue, parameters, col, line);
}

void	palette_rgb(double iteration, t_parameters *parameters,
					int col, int line)
{
	double	current_hue;

	if (iteration == parameters->info->max_iterations)
	{
		parameters->screen->image_data[line * parameters->screen->window_size[0]
		+ col] = colour_in_int(0, 0, 0);
		return ;
	}
	current_hue = parameters->background_hue - iteration *
	parameters->info->colour_gradient;
	if (current_hue < 0)
		current_hue += 360;
	hsb_to_rgb(current_hue, parameters, col, line);
}

void	palette_bw(double iteration, t_parameters *parameters,
					int col, int line)
{
	int	current_rgb;

	current_rgb = (int)floor(iteration * parameters->info->colour_gradient);
	parameters->screen->image_data[line * parameters->screen->window_size[0]
		+ col] = colour_in_int(current_rgb, current_rgb, current_rgb);
}

void	colours(double iteration, t_parameters *parameters,
				int col, int line)
{
	if (parameters->palette == RGB)
		palette_rgb(iteration, parameters, col, line);
	else if (parameters->palette == BW)
		palette_bw(iteration, parameters, col, line);
	else if (parameters->palette == FIXED_COLORS)
		palette_fixed_colours(iteration, parameters, col, line);
}
