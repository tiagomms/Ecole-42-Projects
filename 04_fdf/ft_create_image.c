/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:18:17 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/10 22:55:48 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_image(t_params *to_be_cleared)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(to_be_cleared->image->imgsize[1] *
				to_be_cleared->image->imgsize[0]))
		to_be_cleared->image->img_data[i++] = 0x000000;
}

t_image	ft_create_image(t_params *fdf)
{
	t_image	new_img;

	new_img.imgsize[0] = fdf->info->winsize[0];
	new_img.imgsize[1] = fdf->info->winsize[1];
	new_img.img = mlx_new_image(fdf->info->start, new_img.imgsize[0],
			new_img.imgsize[1]);
	new_img.img_data = (unsigned int*)mlx_get_data_addr(new_img.img,
			&(new_img.bits_p_pxl), &(new_img.size_line), &(new_img.endian));
	new_img.endian = 1;
	new_img.size_line /= 4;
	if (new_img.bits_p_pxl != 32 || new_img.endian != 1)
	{
		ft_return_errs(1, "ft_create_image");
		exit(42);
	}
	return (new_img);
}
