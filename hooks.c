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
	ft_putstr("Keycode: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (keycode);
}

int		mouse_hook(int button, int x, int y, t_parameters *parameters)
{
	if (button == 1)
	{
		parameters->info->central_point[0] = get_current_x0(parameters, x);
		parameters->info->central_point[1] = get_current_y0(parameters, y);
		//discover double limit from tanguy
		parameters->info->zoom++;
	}
	if (button == 3 && parameters->info->zoom > 1)
	{
		parameters->info->central_point[0] = get_current_x0(parameters, x);
		parameters->info->central_point[1] = get_current_y0(parameters, y);
		parameters->info->zoom--;
	}
	if (parameters->info->zoom == 1)
		set_info(parameters->info, parameters->screen);
	else
		set_new_info(parameters->info, parameters->screen);
	handle_fractol(parameters);
	mlx_put_image_to_window(parameters->screen->mlx_ptr,
						parameters->screen->window, 
						parameters->screen->image_ptr, 0, 0);
/*	ft_putchar('\n');
	ft_putstr("Button : ");
	ft_putnbr(button);
	ft_putstr("   --> x: ");
	ft_putnbr(x);
	ft_putstr("  ;  y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	printf("CurrentPoint: |%f|   |%f|\n", get_current_x0(parameters, x),
			get_current_y0(parameters, y));*/
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
