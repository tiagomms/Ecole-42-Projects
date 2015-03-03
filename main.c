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

void	mlx(t_fractype fractype, t_info *info)
{
	t_screen		screen;
	t_parameters	parameters;

	set_screen(&screen);
	parameters.screen = &screen;
	parameters.info = info;
	parameters.fractype = fractype;
	set_info(parameters.info, parameters.screen, &parameters);//add fractype after
	mlx_expose_hook(parameters.screen->window, expose_hook, &parameters);
	mlx_mouse_hook(parameters.screen->window, mouse_hook, &parameters);
	mlx_hook(parameters.screen->window, 6, 1L << 6,
				mouse_motion_hook, &parameters);
	mlx_key_hook(parameters.screen->window, key_hook, &parameters);
	mlx_loop_hook(parameters.screen->mlx_ptr, loop_hook, &parameters);
	mlx_loop(parameters.screen->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_fractype	fractype;
	t_info		info;

	if (argc == 2 || argc == 3)
	{
		if (!(ft_strcmp(argv[1], "mandelbrot")))
			fractype = MANDELBROT; // check flags Makefile
		else if (!(ft_strcmp(argv[1], "julia")))
			fractype = JULIA;
		else if (!(ft_strcmp(argv[1], "burning")))
			fractype = BURNING;
		else if (!(ft_strcmp(argv[1], "other1")))
			fractype = OTHER1;
		else if (!(ft_strcmp(argv[1], "other2")))
			fractype = OTHER2;
		else if (!(ft_strcmp(argv[1], "other3")))
			fractype = OTHER3;
		else if (!(ft_strcmp(argv[1], "nova")))
			fractype = NOVA;
		else if (!(ft_strcmp(argv[1], "other5")))
			fractype = OTHER5;
		else if (!(ft_strcmp(argv[1], "other6")))
			fractype = OTHER6;
		else
		{
			ft_putstr_fd("Invalid Selection\n", 2);
			exit(0);
		}
		if (argc == 3)
			info.max_iterations = custom_atoi(argv[2]);
		else
			info.max_iterations = 100;
	}
	mlx(fractype, &info);
	return (0);
}
