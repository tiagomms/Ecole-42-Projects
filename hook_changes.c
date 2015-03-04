/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_changes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:52:10 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/04 10:52:17 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	changing_palettes(int keycode, t_parameters *parameters)
{
	if (keycode == 'b')
		parameters->palette = BW;
	else if (keycode == 'n')
		parameters->palette = RGB;
	else if (keycode == 'm')
		parameters->palette = FIXED_COLORS;
	else if (keycode == 'q' && parameters->palette == RGB)
		parameters->background_hue += 10;
	else if (keycode == 'w' && parameters->palette == RGB)
		parameters->background_hue -= 10;
	else
		return ;
	if (parameters->background_hue < 0)
		parameters->background_hue += 360;
	else if (parameters->background_hue > 360)
		parameters->background_hue -= 360;
	parameters->update = 1;
}

void	moving_with_arrows(int keycode, t_parameters *parameters)
{
	double move;

	if (if_julia_and_others(parameters) && !parameters->lock_activated)
		return ;
	move = (parameters->info->initial_axis_length / 5);
	move /= parameters->info->zoom;
	if (move <= 0.0000000000002f)
		move = 0.0000000000002f;
	if (keycode == 65361)
		parameters->info->central_point[0] -= move;
	else if (keycode == 65363)
		parameters->info->central_point[0] += move;
	else if (keycode == 65362)
		parameters->info->central_point[1] += move;
	else if (keycode == 65364)
		parameters->info->central_point[1] -= move;
	else
		return ;
	set_new_info(parameters->info, parameters->screen);
	parameters->update = 1;
}

void	changing_fractal(int keycode, t_parameters *parameters)
{
	if (keycode == 49)
		parameters->fractype = JULIA;
	else if (keycode == 50)
		parameters->fractype = MANDELBROT;
	else if (keycode == 51)
		parameters->fractype = BURNING;
	else if (keycode == 52)
		parameters->fractype = OTHER1;
	else if (keycode == 53)
		parameters->fractype = OTHER2;
	else if (keycode == 54)
		parameters->fractype = OTHER3;
	else if (keycode == 55)
		parameters->fractype = NOVA;
	else if (keycode == 56)
		parameters->fractype = OTHER4;
	else if (keycode == 57)
		parameters->fractype = OTHER5;
	else
		return ;
	set_info(parameters->info, parameters->screen, parameters);
	parameters->update = 1;
}

void	changing_relaxation_const(int keycode, t_parameters *parameters)
{
	if (parameters->fractype == NOVA && (keycode == 'z' || keycode == 'x'
		|| keycode == 'r'))
	{
		if (keycode == 'z' && parameters->relaxation_c < 6)
			parameters->relaxation_c++;
		if (keycode == 'x' && parameters->relaxation_c > 1)
			parameters->relaxation_c--;
		if (parameters->relaxation_c == 1)
			parameters->info->initial_axis_length = 2.5;
		else if (parameters->relaxation_c == 2)
			parameters->info->initial_axis_length = 7;
		else if (parameters->relaxation_c == 3)
			parameters->info->initial_axis_length = 9;
		else if (parameters->relaxation_c == 4)
			parameters->info->initial_axis_length = 10;
		else if (parameters->relaxation_c == 5)
			parameters->info->initial_axis_length = 8;
		else if (parameters->relaxation_c == 6)
			parameters->info->initial_axis_length = 2.5;
		parameters->info->zoom = 1;
		parameters->lock_activated = 0;
		set_new_info(parameters->info, parameters->screen);
		parameters->update = 1;
	}
}
