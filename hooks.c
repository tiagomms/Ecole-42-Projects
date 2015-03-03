/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:57:38 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/02 16:59:46 by mbooth           ###   ########.fr       */
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
		parameters->fractype = OTHER5;
	else if (keycode == 57)
		parameters->fractype = OTHER6;
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
	ft_putstr("Keycode: ");//
	ft_putnbr(keycode);//
	ft_putchar('\n');//
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
		printf("JULIA: mouse_motion activated --> (x, y) - (%f, %f)\n", parameters->info->current_point[0], parameters->info->current_point[1]);//	
	}
}

int		mouse_hook(int button, int x, int y, t_parameters *parameters)
{
	static int rolling = 0;

	if (if_julia_and_others(parameters) && !parameters->lock_activated)
		return (0);
	if (button == 1 || button == 3)
	{
		parameters->info->central_point[0] = get_current_x0(parameters, x);
		parameters->info->central_point[1] = get_current_y0(parameters, y);
		set_new_info(parameters->info, parameters->screen);
		parameters->update = 1;
	}
	else if ((button == 4 || button == 5) && rolling == 0)
	{
		rolling = 1;
		if (button == 5 && (2.5 / (parameters->info->zoom * 1.05)) > 0.000000000001f)//limits of zoom don't work
			parameters->info->zoom *= 1.05f;//epsilon changed
		else if (parameters->info->zoom > 1)
			parameters->info->zoom /= 1.05f;
		if (parameters->info->zoom <= 1)
			set_info(parameters->info, parameters->screen, parameters);
		else
			set_new_info(parameters->info, parameters->screen);
		parameters->update = 1;
		rolling = 0;
	}
	printf("\nbutton %d ; zoom = %lf\n", button, parameters->info->zoom);
	return (button);
}

int		expose_hook(t_parameters *parameters)
{
	handle_fractol(parameters);
	mlx_put_image_to_window(parameters->screen->mlx_ptr,
						parameters->screen->window, 
						parameters->screen->image_ptr, 0, 0);
	return (1);
}
