/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:28:22 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/10 23:00:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	expose_projection(t_params **p_to_expose)
{
	size_t	x;
	size_t	y;
	t_list	*list;
	void	(*ft_proj)(t_params*, size_t, size_t, t_list*);

	list = (*p_to_expose)->list;
	ft_set_colors(*p_to_expose);
	y = 0;
	if ((*p_to_expose)->keycode == '2' || (*p_to_expose)->keycode == 65458)
		ft_proj = &draw_parallel;
	else if ((*p_to_expose)->keycode == 0 || (*p_to_expose)->keycode == '1' ||
			(*p_to_expose)->keycode == 65457)
		ft_proj = &draw_isometric;
	while (list)
	{
		x = 0;
		while (x++ < list->content_size)
			ft_proj(*p_to_expose, x - 1, y, list);
		y++;
		list = list->next;
	}
	return (0);
}

static int	if_key_is_activated(int key)
{
	if (key == 0 || key == '1' || key == '2' || key == 65457 || key == 65458
			|| key == 'r' || key == 'b' || key == 'f' || key == 'g' ||
			key == 'w')
		return (1);
	return (0);
}

static int	key_quit(int keycode, t_params *params)
{
	if (keycode == 65307)
	{
		ft_putstr_fd("\nWINDOW CLOSED\n", 2);
		exit(0);
	}
	if (keycode == 65457 || keycode == 65458 || keycode == '1' ||
			keycode == '2')
		params->keycode = keycode;
	else
		params->keycode_2 = keycode;
	if (if_key_is_activated(keycode))
	{
		ft_clear_image(params);
		get_s_image_test(params, params->keycode);
		expose_projection(&params);
		mlx_put_image_to_window(params->info->start, params->info->window,
				params->image->img, 0, 0);
	}
	return (keycode);
}

static int	expose_it(t_params *params)
{
	expose_projection(&params);
	mlx_put_image_to_window(params->info->start, params->info->window,
			params->image->img, 0, 0);
	ft_putstr_fd("\nBienvenue! Instructions:\n\n", 2);
	ft_putstr_fd("Press:\n", 2);
	ft_putstr_fd("\nFor different projections:\n", 2);
	ft_putstr_fd("1 - Isometric\n", 2);
	ft_putstr_fd("2 - Parallel\n", 2);
	ft_putstr_fd("\nFor different palettes:\n", 2);
	ft_putstr_fd("g - 42 (noir, grix, blanc)\n", 2);
	ft_putstr_fd("f - Facebook (bleu, light bleu, blanc)\n", 2);
	ft_putstr_fd("b - Heat Map (bleu, green, red)\n", 2);
	ft_putstr_fd("w ou r - Standard blanc\n", 2);
	return (0);
}

void		mlx(t_list *list_in_mlx, t_list *inserted_colors)
{
	t_info		mlx_inf;
	t_params	parameters;
	t_image		proj_test;

	mlx_inf.winsize[0] = 1800;
	mlx_inf.winsize[1] = 1200;
	mlx_inf.nbr_lines = ft_lstsize(&list_in_mlx);
	mlx_inf.nbr_cols_max = ft_max_contentsize(&list_in_mlx);
	ft_min_max_nbr_list(&list_in_mlx, &mlx_inf);
	mlx_inf.start = mlx_init();
	mlx_inf.window = mlx_new_window(mlx_inf.start, mlx_inf.winsize[0],
			mlx_inf.winsize[1], "42");
	parameters.list = list_in_mlx;
	parameters.colorpos = inserted_colors;
	parameters.info = &mlx_inf;
	proj_test = ft_create_image(&parameters);
	parameters.image = &proj_test;
	parameters.keycode = 0;
	parameters.keycode_2 = 0;
	get_s_image_test(&parameters, parameters.keycode);
	mlx_expose_hook(mlx_inf.window, expose_it, &parameters);
	mlx_key_hook(mlx_inf.window, key_quit, &parameters);
	mlx_loop(mlx_inf.start);
}
