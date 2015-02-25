/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:18:24 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/25 17:18:26 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_parameters *parameters)
{
	handle_fractol(&parameters);
	mlx_put_image_to_window(parameters->screen->mlx_ptr,
						parameters->screen->window, 
						parameters->screen->image_ptr, 0, 0);
}

void	mlx(t_fractype *fractype, t_info *info)
{
	t_screen		screen;
	t_parameters	parameters;

	set_screen(&screen);
	set_info(info, &screen);//add fractype after
	parameters.screen = &screen;
	parameters.info = info;
	mlx_expose_hook(parameters.screen->window, expose_hook, &parameters);
	mlx_mouse_hook(parameters.screen->window, mouse_hook, &parameters);
	mlx_key_hook(parameters.screen->window, key_hook, &parameters);
	mlx_loop(parameters.screen->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_fractype	fractype;
	t_info		info;

	if (argc == 3)
	{
		if (!(ft_strcmp(argv[1], "mandelbrot")))
			fractype = MANDELBROT;
		else if (!(ft_strcmp(argv[1], "julia")))
			fractype = JULIA;
		else if (!(ft_strcmp(argv[1], "other")))
			fractype = OTHER;
		//else error
		info.iterations = custom_atoi(argv[2]);
	}
	mlx(&fractype, &info);
	return (0);
}
