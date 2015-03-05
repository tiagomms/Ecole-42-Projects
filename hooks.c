/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:57:38 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/05 14:49:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_parameters *parameters)
{
	double	relaxation_const;

	relaxation_const = parameters->relaxation_c;
	if (keycode == 65307)
	{
		ft_putstr_fd("\nWINDOW CLOSED\n", 1);
		exit(0);
	}
	if (keycode == 'r')
	{
		set_info(parameters->info, parameters->screen, parameters);
		parameters->relaxation_c = relaxation_const;
		parameters->update = 1;
	}
	if (keycode == 'l')
		parameters->lock_activated = 1;
	if (keycode == 'u')
		parameters->lock_activated = 0;
	moving_with_arrows(keycode, parameters);
	changing_palettes(keycode, parameters);
	changing_fractal(keycode, parameters);
	changing_relaxation_const(keycode, parameters);
	return (keycode);
}

int		loop_hook(t_parameters *parameters)
{
	static int displaying = 0;

	if (displaying == 1)
		return (0);
	if (parameters->update == 0)
		return (0);
	displaying = 1;
	parameters->update = 0;
	handle_fractol(parameters);
	print_display(parameters, parameters->screen);
	mlx_put_image_to_window(parameters->screen->mlx_ptr,
					parameters->screen->window,
					parameters->screen->image_ptr, 0, 0);
	displaying = 0;
	return (1);
}

int		mouse_motion_hook(int x, int y, t_parameters *parameters)
{
	static int moving = 0;

	if (if_julia_and_others(parameters) &&
		parameters->lock_activated == 0 &&
		moving == 0 && x <= parameters->screen->window_size[0])
	{
		moving = 1;
		parameters->info->current_point[0] = get_current_x0(parameters, x);
		parameters->info->current_point[1] = get_current_y0(parameters, y);
		parameters->update = 1;
		moving = 0;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_parameters *parameters)
{
	static int	rolling = 0;

	if (if_julia_and_others(parameters) && !parameters->lock_activated)
		return (0);
	if (button == 1 || button == 3)
		change_central_point(parameters, x, y);
	else if ((button == 4 || button == 5) && rolling == 0)
	{
		rolling = 1;
		if (button == 5 && (parameters->info->initial_axis_length /
			(parameters->info->zoom * 1.05)) > 0.000000000001f)
			parameters->info->zoom *= 1.05f;
		else if (button == 4 && parameters->info->zoom > 1)
			parameters->info->zoom /= 1.05f;
		if (parameters->info->zoom < 1)
			parameters->info->zoom = 1;
		set_new_info(parameters->info, parameters->screen);
		parameters->update = 1;
		rolling = 0;
	}
	return (button);
}

int		expose_hook(t_parameters *parameters)
{
	print_menu(parameters->screen);
	handle_fractol(parameters);
	print_display(parameters, parameters->screen);
	mlx_put_image_to_window(parameters->screen->mlx_ptr,
						parameters->screen->window,
						parameters->screen->image_ptr, 0, 0);
	return (1);
}
