/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:57:38 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/26 10:57:48 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	key_hook(int keycode, t_parameters *parameters)
{
	if (keycode == 65307)
	{
		ft_putstr_fd("\nWINDOW CLOSED\n", 1);
		exit(0);
	}
	if (keycode == 114)
	{
		set_info(parameters->info, parameters->screen);
		parameters->update = 1;
	}
	if (keycode == 108)
		parameters->info->lock_activated = 1;
	if (keycode == 117)
		parameters->info->lock_activated = 0;
	ft_putstr("Keycode: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
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

	if (parameters->fractype == JULIA &&
		parameters->info->lock_activated == 0 &&
		moving == 0)
	{
		moving = 1;
		parameters->info->current_point[0] = get_current_x0(parameters, x);
		parameters->info->current_point[1] = get_current_y0(parameters, y);
		parameters->update = 1;
		moving = 0;
		printf("JULIA: mouse_motion activated --> (x, y) - (%f, %f)\n", parameters->info->central_point[0], parameters->info->central_point[1]);//	
	}
}

int		mouse_hook(int button, int x, int y, t_parameters *parameters)
{
	static int rolling = 0;

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
		if (button == 5 && (2.5 / parameters->info->zoom) > 0.000000000001f)//limits of zoom don't work
			parameters->info->zoom *= 1.1f;//epsilon changed
		else if (parameters->info->zoom > 1)
			parameters->info->zoom /= 1.1f;
		if (parameters->info->zoom <= 1)
			set_info(parameters->info, parameters->screen);
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
	return (1); //double check this
}
