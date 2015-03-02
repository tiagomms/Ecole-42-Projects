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

double	ft_abs_double(double n)
{
	return (n < 0 ? -n : n);
}

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

void	handle_fractol(t_parameters *parameters)
{
	if (parameters->fractype == JULIA)
		handle_julia(parameters);
	if (parameters->fractype == MANDELBROT)
		handle_mandelbrot(parameters);
	if (parameters->fractype == OTHER)
		handle_burning_ship(parameters);
}