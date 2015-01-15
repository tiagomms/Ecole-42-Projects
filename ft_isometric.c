/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:39:50 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 19:38:24 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	*proj_isometric(size_t col, size_t line, int z, t_image *p_i)
{
	double angle_x;
	double angle_y;
	double *isometric;
	double pi;

	angle_x = 60;
	angle_y = 45;
	pi = acos(-1);
	isometric = (double*)ft_memalloc(sizeof(double) * 2);
	isometric[0] = floor(p_i->ratio[0] * ((sin(pi * angle_x / 180) * col)
				+ (-cos(pi * angle_y / 180) * line)));
	isometric[1] = floor(p_i->ratio[1] * (cos(pi * angle_x / 180) * col +
			sin(pi * angle_y / 180) * line) - (z * p_i->img_slope));
	return (isometric);
}

static void		part_2_draw_isometric(t_params *p_iso, size_t j, size_t i,
		t_list *list)
{
	double	*points_draw_l[2];
	int		z1;
	int		z2;

	z1 = ((int*)list->content)[j];
	if (j != list->content_size - 1)
	{
		z2 = ((int*)list->content)[j + 1];
		p_iso->point_lin_col = 2;
		points_draw_l[0] = proj_isometric(j, i, z1, p_iso->image);
		points_draw_l[1] = proj_isometric(j + 1, i, z2, p_iso->image);
		mlx_put_pixel_image(points_draw_l, p_iso, z1, z2);
		ft_memdel((void**)&points_draw_l[0]);
		ft_memdel((void**)&points_draw_l[1]);
	}
	if (i != p_iso->info->nbr_lines - 1 && j != list->next->content_size)
	{
		z2 = ((int*)list->next->content)[j];
		p_iso->point_lin_col = 1;
		points_draw_l[0] = proj_isometric(j, i, z1, p_iso->image);
		points_draw_l[1] = proj_isometric(j, i + 1, z2, p_iso->image);
		mlx_put_pixel_image(points_draw_l, p_iso, z1, z2);
		ft_memdel((void**)&points_draw_l[0]);
		ft_memdel((void**)&points_draw_l[1]);
	}
}

void			draw_isometric(t_params *p_iso, size_t j, size_t i,
		t_list *list)
{
	double	*point_1_draw_lin;
	int		z1;

	z1 = ((int*)list->content)[j];
	p_iso->current_coor[0] = i;
	p_iso->current_coor[1] = j;
	if ((p_iso->info->nbr_lines == 1 && p_iso->info->nbr_cols_max == 1) ||
			(i == p_iso->info->nbr_lines - 1 && j == list->content_size - 1))
	{
		point_1_draw_lin = proj_isometric(j, i, z1, p_iso->image);
		p_iso->point_lin_col = 0;
		p_iso->image->img_data[(int)(floor(point_1_draw_lin[1] +
					p_iso->image->i_pos[1]) * p_iso->image->size_line +
				floor(point_1_draw_lin[0] + p_iso->image->i_pos[0]))] =
			ft_color_42(z1, p_iso, p_iso->point_lin_col);
		ft_memdel((void**)&point_1_draw_lin);
	}
	part_2_draw_isometric(p_iso, j, i, list);
}
