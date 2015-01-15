/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_42.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:49:01 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 16:06:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	coordcmp_columncase(t_list **c_l, t_params *crd)
{
	t_list	*find_column;

	find_column = *c_l;
	if (!c_l || !(find_column = *c_l))
		return (0);
	find_column = find_column->next;
	while (find_column)
	{
		if ((int)crd->current_coor[0] + 1 == ((int*)find_column->content)[0]
				&& (int)crd->current_coor[1] == ((int*)find_column->content)[1])
			return (1);
		find_column = find_column->next;
	}
	return (0);
}

static int	coordcmp(t_list **first_color_pos, t_params *crd, int lineorcol)
{
	t_list	*c_l;

	if (!first_color_pos || !(c_l = *first_color_pos))
		return (0);
	while (c_l)
	{
		if ((int)crd->current_coor[0] == ((int*)c_l->content)[0] &&
				(int)crd->current_coor[1] == ((int*)c_l->content)[1])
		{
			if (lineorcol == 0 || crd->dot == 0)
				return (((int*)c_l->content)[2]);
			if (c_l->next && crd->dot == 1)
				if ((lineorcol == 2 && (int)crd->current_coor[0] ==
						((int*)c_l->next->content)[0]
						&& (int)crd->current_coor[1] + 1 ==
						((int*)c_l->next->content)[1]) ||
						(lineorcol == 1 && coordcmp_columncase(&c_l, crd)))
					return (((int*)c_l->content)[2]);
		}
		c_l = c_l->next;
	}
	return (0);
}

int			ft_color_42(double current_z, t_params *par, int line_col)
{
	int			current_color[3];
	int			i;
	t_list		*color_location;
	int			color_attributed;

	i = -1;
	color_location = par->colorpos;
	if ((color_attributed = coordcmp(&color_location, par, line_col)) != 0)
		return (color_attributed);
	while (++i < 3)
	{
		if (current_z > par->info->min_mid_max[1])
			current_color[i] = (int)floor((current_z -
						par->info->min_mid_max[1]) *
				(par->image->color_slopes)[1][i] + (par->image->colors)[1][i]);
		else
			current_color[i] = (int)floor((current_z -
						par->info->min_mid_max[0]) *
				(par->image->color_slopes)[0][i] + (par->image->colors)[0][i]);
	}
	return (color_in_int(current_color[0], current_color[1], current_color[2]));
}
