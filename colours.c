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

void	palette_rgb(double iteration, t_parameters *parameters, int col, int line)
{
	int		thid_max_iterations;
	int		current_rgb;

	thid_max_iterations = parameters->info->max_iterations / 3;
	current_rgb = (int)floor(((int)iteration % thid_max_iterations) * 3 * parameters->info->colour_gradient);
	if (iteration <= thid_max_iterations)
		parameters->screen->image_data[line * parameters->screen->window_size[0] 
		+ col] = colour_in_int(current_rgb, 0, 0);
	else if (iteration <= 2 * thid_max_iterations)
		parameters->screen->image_data[line * parameters->screen->window_size[0] 
		+ col] = colour_in_int(0, current_rgb, 0);
	else
		parameters->screen->image_data[line * parameters->screen->window_size[0] 
		+ col] = colour_in_int(0, 0, current_rgb);
}

void	palette_bw(double iteration, t_parameters *parameters, int col, int line)
{
	int	current_rgb;

	current_rgb = (int)floor(iteration * parameters->info->colour_gradient);
	parameters->screen->image_data[line * parameters->screen->window_size[0] 
		+ col] = colour_in_int(current_rgb, current_rgb, current_rgb);
}

/*void	palette_third(double iteration, t_parameters *parameters, int col, int line)
{

}*/

void	colours(double iteration, t_parameters *parameters, int col, int line)
{
	if (parameters->palette == RGB)
		palette_rgb(iteration, parameters, col, line);
	else if (parameters->palette == BW)
		palette_bw(iteration, parameters, col, line);
	//else if (parameters->palette == THIRD)
	//	palette_third(iteration, parameters, col, line);
}
