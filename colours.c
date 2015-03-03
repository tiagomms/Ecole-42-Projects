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

void	hsb_to_rgb(double current_hue, t_parameters *parameters,
					int col, int line)
{
	double	hue_sector;
	double	brightness;
	double	intermediate;
	double	remaining;
	int		rgb[3];

	hue_sector = current_hue / 60.0;
	remaining = hue_sector;
	while (remaining > 2.0)
		remaining -= 2.0;
	brightness = 0.9;
	intermediate = brightness * (1 - ft_abs_double(remaining - 1.0));
	if (hue_sector < 1)
	{
		rgb[0] = brightness * 255;
		rgb[1] = intermediate * 255;
		rgb[2] = 0;
	}
	else if (hue_sector < 2)
	{
		rgb[0] = intermediate * 255;
		rgb[1] = brightness * 255;
		rgb[2] = 0;
	}
	else if (hue_sector < 3)
	{
		rgb[0] = 0;
		rgb[1] = brightness * 255;
		rgb[2] = intermediate * 255;
	}
	else if (hue_sector < 4)
	{
		rgb[0] = 0;
		rgb[1] = intermediate * 255;
		rgb[2] = brightness * 255;
	}
	else if (hue_sector < 5)
	{
		rgb[0] = intermediate * 255;
		rgb[1] = 0;
		rgb[2] = brightness * 255;
	}
	else
	{
		rgb[0] = brightness * 255;
		rgb[1] = 0;
		rgb[2] = intermediate * 255;
	}
	parameters->screen->image_data[line * parameters->screen->window_size[0] 
		+ col] = colour_in_int(rgb[0], rgb[1], rgb[2]);
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
	current_hue = parameters->background_hue - iteration * parameters->info->colour_gradient;
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
