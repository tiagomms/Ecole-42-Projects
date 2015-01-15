/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:07:32 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/10 23:15:24 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_super_gradient(t_image *super_colors)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		super_colors->colors[i][0] = 0;
		super_colors->colors[i][1] = 0;
		super_colors->colors[i][2] = 0;
		super_colors->colors[i][2 - i] = 255;
	}
}

static void	set_facebook_gradient(t_image *facebook_colors)
{
	int i;

	i = -1;
	facebook_colors->colors[0][0] = 59;
	facebook_colors->colors[0][1] = 89;
	facebook_colors->colors[0][2] = 152;
	facebook_colors->colors[1][0] = 139;
	facebook_colors->colors[1][1] = 157;
	facebook_colors->colors[1][2] = 195;
	while (++i < 3)
		facebook_colors->colors[2][i] = 247;
}

static void	set_42_gradient(t_image *fortytwo_colors)
{
	int i;

	i = -1;
	while (++i < 3)
		fortytwo_colors->colors[0][i] = 77;
	i = -1;
	while (++i < 3)
		fortytwo_colors->colors[1][i] = 150;
	i = -1;
	while (++i < 3)
		fortytwo_colors->colors[2][i] = 255;
}

void		ft_color_slopes(t_params *clr_i)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 3)
		{
			if (clr_i->info->min_mid_max[i + 1] == clr_i->info->min_mid_max[i])
				clr_i->image->color_slopes[i][j] = 0;
			else
				clr_i->image->color_slopes[i][j] =
					((clr_i->image->colors[i + 1][j] -
					clr_i->image->colors[i][j]) /
					((double)(clr_i->info->min_mid_max[i + 1] -
					clr_i->info->min_mid_max[i])));
		}
	}
}

void		ft_set_colors(t_params *image_w_colors)
{
	int	i;

	i = -1;
	if (image_w_colors->keycode_2 == 0 || image_w_colors->keycode_2 == 'r' ||
			image_w_colors->keycode_2 == 'w')
	{
		while (++i < 3)
		{
			image_w_colors->image->colors[i][0] = 255;
			image_w_colors->image->colors[i][1] = 255;
			image_w_colors->image->colors[i][2] = 255;
		}
	}
	else if (image_w_colors->keycode_2 == 'b')
		set_super_gradient(image_w_colors->image);
	else if (image_w_colors->keycode_2 == 'f')
		set_facebook_gradient(image_w_colors->image);
	else if (image_w_colors->keycode_2 == 'g')
		set_42_gradient(image_w_colors->image);
	ft_color_slopes(image_w_colors);
}
