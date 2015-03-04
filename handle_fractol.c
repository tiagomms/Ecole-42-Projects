/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:05:33 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/02 17:02:34 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		if_julia_and_others(t_parameters *parameters)
{
	if (parameters->fractype != MANDELBROT && parameters->fractype != BURNING)
		return (1);
	return (0);
}

double	ft_abs_double(double n)
{
	return (n < 0 ? -n : n);
}

double	get_current_x0(t_parameters *parameters, int col)
{
	double result;

	result = parameters->info->current_limits_x[0] +
				(col * parameters->info->epsilon);
	return (result);
}

double	get_current_y0(t_parameters *parameters, int line)
{
	double result;

	result = parameters->info->current_limits_y[1] -
				(line * parameters->info->epsilon);
	return (result);
}

void	handle_fractol(t_parameters *parameters)
{
	if (parameters->fractype == JULIA)
		handle_julia(parameters);
	if (parameters->fractype == MANDELBROT)
		handle_mandelbrot(parameters);
	if (parameters->fractype == BURNING)
		handle_burning_ship(parameters);
	if (parameters->fractype == OTHER1)
		handle_other1(parameters);
	if (parameters->fractype == OTHER2)
		handle_other2(parameters);
	if (parameters->fractype == OTHER3)
		handle_other3(parameters);
	if (parameters->fractype == NOVA)
		handle_nova(parameters);
	if (parameters->fractype == OTHER4)
		handle_other5(parameters);
	if (parameters->fractype == OTHER5)
		handle_other6(parameters);
}
