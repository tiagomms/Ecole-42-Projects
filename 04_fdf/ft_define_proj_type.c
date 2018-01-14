/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_proj_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:41:24 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 20:34:11 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		isometric_while(t_params *for_iso)
{
	double	current_ratio;

	current_ratio = for_iso->image->ratio[0];
	while (for_iso->image->img_slope > 0 &&
			(for_iso->image->img_slope * for_iso->info->min_mid_max[2] >
			for_iso->image->i_pos[1] ||
			(for_iso->image->img_slope * for_iso->info->min_mid_max[0] >
			for_iso->image->imgsize[1] - for_iso->image->i_pos[1])))
		for_iso->image->img_slope += -0.1;
	while (current_ratio > 0 && ((current_ratio * for_iso->info->nbr_cols_max +
			for_iso->image->i_pos[0] > for_iso->image->imgsize[0]) ||
			(current_ratio * for_iso->info->nbr_lines >
			for_iso->image->i_pos[0]) ||
			(current_ratio * (for_iso->info->nbr_lines +
			for_iso->info->nbr_cols_max) - (for_iso->info->min_mid_max[0] *
			for_iso->image->img_slope) >
			for_iso->image->imgsize[1] - for_iso->image->i_pos[1])))
	{
		if (current_ratio <= 1)
			current_ratio += -0.1;
		else
			current_ratio--;
	}
	for_iso->image->ratio[0] = current_ratio;
	for_iso->image->ratio[1] = for_iso->image->ratio[0];
}

static void		parallel_while(t_params *for_par)
{
	double	current_ratio;

	current_ratio = for_par->image->ratio[0];
	while (for_par->image->img_slope > 0 &&
			((for_par->image->img_slope * for_par->info->min_mid_max[2] >
			for_par->image->i_pos[1]) ||
			(ft_abs(for_par->info->min_mid_max[0]) * for_par->image->img_slope >
			for_par->image->i_pos[0])))
		for_par->image->img_slope += -0.1;
	while (current_ratio > 0 && ((current_ratio * for_par->info->nbr_cols_max +
			for_par->image->img_slope * for_par->info->min_mid_max[2] >
			for_par->image->imgsize[0] - for_par->image->i_pos[0]) ||
			(current_ratio * for_par->info->nbr_lines -
			for_par->info->min_mid_max[0] * for_par->image->img_slope >
			for_par->image->imgsize[1] - for_par->image->i_pos[1])))
		current_ratio--;
	for_par->image->ratio[0] = current_ratio;
	for_par->image->ratio[1] = for_par->image->ratio[0];
}

void			get_s_image_test(t_params *set_up, int keycode)
{
	set_up->image->ratio[0] = 50;
	set_up->image->img_slope = 2;
	if (keycode == 0 || keycode == '1' || keycode == 65457)
	{
		set_up->image->i_pos[0] = (set_up->image->imgsize[0] / 2) - 200;
		set_up->image->i_pos[1] = 100;
		isometric_while(set_up);
	}
	else if (keycode == '2' || keycode == 65458)
	{
		set_up->image->i_pos[0] = 100;
		set_up->image->i_pos[1] = 100;
		parallel_while(set_up);
	}
}
