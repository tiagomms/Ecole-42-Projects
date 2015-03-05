/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:18:24 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/25 17:18:26 by tsilva           ###   ########.fr       */
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
	set_info(parameters.info, parameters.screen, &parameters);
	mlx_expose_hook(parameters.screen->window, expose_hook, &parameters);
	mlx_mouse_hook(parameters.screen->window, mouse_hook, &parameters);
	mlx_hook(parameters.screen->window, 6, 1L << 6,
				mouse_motion_hook, &parameters);
	mlx_key_hook(parameters.screen->window, key_hook, &parameters);
	mlx_loop_hook(parameters.screen->mlx_ptr, loop_hook, &parameters);
	mlx_loop(parameters.screen->mlx_ptr);
}

int		get_fractype(char **argv, t_fractype *fractype)
{
	if (!(ft_strcmp(argv[1], "mandelbrot")))
		*fractype = MANDELBROT;
	else if (!(ft_strcmp(argv[1], "julia")))
		*fractype = JULIA;
	else if (!(ft_strcmp(argv[1], "burning")))
		*fractype = BURNING;
	else if (!(ft_strcmp(argv[1], "other1")))
		*fractype = OTHER1;
	else if (!(ft_strcmp(argv[1], "other2")))
		*fractype = OTHER2;
	else if (!(ft_strcmp(argv[1], "other3")))
		*fractype = OTHER3;
	else if (!(ft_strcmp(argv[1], "nova")))
		*fractype = NOVA;
	else if (!(ft_strcmp(argv[1], "other4")))
		*fractype = OTHER4;
	else if (!(ft_strcmp(argv[1], "other5")))
		*fractype = OTHER5;
	else
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fractype	fractype;
	t_info		info;

	fractype = 0;
	if (argc == 2 || argc == 3)
	{
		if (get_fractype(argv, &fractype))
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
