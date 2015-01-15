/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_put_pixel_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 16:23:30 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 17:06:28 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		stop_while_2(double point_1[], double point_2[], int code[])
{
	if (code[0] == -1 && code[1] == 1)
		return (point_2[1] > point_1[1]);
	if (code[0] == -1 && code[1] == 0)
		return (point_2[1] < point_1[1]);
	if (code[0] == 1)
		return (point_2[0] > point_1[0]);
	return (point_2[0] < point_1[0]);
}

static int		q(double *ps[], t_params *v)
{
	int	pixel_in_the_image;

	pixel_in_the_image = (int)(floor(ps[0][1] + v->image->i_pos[1]) *
				v->image->size_line + floor(ps[0][0] + v->image->i_pos[0]));
	return (pixel_in_the_image);
}

static double	ft_nbr_pixels_put(double *points[], int size)
{
	double	norme;
	int		i;

	i = -1;
	norme = 0;
	while (++i < size)
		norme += ft_abs_d(points[1][i] - points[0][i]);
	return (norme != 0 ? norme : 1);
}

static void		mlx_put_pixel_image_part2(double *ps[], t_params *v,
		double z, double slopes[])
{
	int		the_norme[2];
	double	error;
	double	x0_y0[2];

	the_norme[0] = (ps[1][0] == ps[0][0] ? -1 : (ps[1][0] > ps[0][0]));
	the_norme[1] = (ps[1][1] > ps[0][1]);
	error = 0;
	x0_y0[1] = ps[0][1];
	x0_y0[0] = ps[0][0];
	while (stop_while_2(ps[0], ps[1], the_norme))
	{
		v->image->img_data[q(ps, v)] = ft_color_42(z, v, v->point_lin_col);
		error += slopes[0];
		z += slopes[1];
		while (error >= 0.5 && stop_while_2(ps[0], ps[1], the_norme))
		{
			v->image->img_data[q(ps, v)] = ft_color_42(z, v, v->point_lin_col);
			v->dot = 1;
			ps[0][1] += ft_sgn((int)(ps[1][1] - x0_y0[1]));
			z += slopes[1];
			error--;
		}
		v->dot = 1;
		ps[0][0] += ft_sgn((int)(ps[1][0] - x0_y0[0]));
	}
}

void			mlx_put_pixel_image(double *points[], t_params *v,
		int z1, int z2)
{
	double	slopes[2];
	double	current_z;

	if (points[1][0] - points[0][0] != 0)
		slopes[0] = ft_abs_d((points[1][1] - points[0][1]) / (points[1][0] -
					points[0][0]));
	else
		slopes[0] = ft_abs_d((points[1][1] - points[0][1]));
	slopes[1] = ((z2 - z1) / ft_nbr_pixels_put(points, 2));
	current_z = (double)z1;
	v->dot = 0;
	mlx_put_pixel_image_part2(points, v, current_z, slopes);
}
