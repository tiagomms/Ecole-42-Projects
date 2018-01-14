/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsb_colour_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:37:58 by tsilva            #+#    #+#             */
/*   Updated: 2015/03/04 10:38:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	continue_colour_conversion(double hue_sector, double brightness,
										double intermediate, int *rgb)
{
	if (hue_sector < 4)
	{
		rgb[0] = 0;
		rgb[1] = intermediate * 255;
		rgb[2] = brightness * 255;
	}
	else if (hue_sector < 5)
	{
		rgb[0] = intermediate * 255;
		rgb[1] = 0;
		rgb[2] = brightness * 255;
	}
	else
	{
		rgb[0] = brightness * 255;
		rgb[1] = 0;
		rgb[2] = intermediate * 255;
	}
}

static void	colour_conversion(double hue_sector, double brightness,
								double intermediate, int *rgb)
{
	if (hue_sector < 1)
	{
		rgb[0] = brightness * 255;
		rgb[1] = intermediate * 255;
		rgb[2] = 0;
	}
	else if (hue_sector < 2)
	{
		rgb[0] = intermediate * 255;
		rgb[1] = brightness * 255;
		rgb[2] = 0;
	}
	else if (hue_sector < 3)
	{
		rgb[0] = 0;
		rgb[1] = brightness * 255;
		rgb[2] = intermediate * 255;
	}
	else
		continue_colour_conversion(hue_sector, brightness, intermediate, rgb);
}

void		hsb_to_rgb(double current_hue, t_parameters *parameters,
					int col, int line)
{
	double	hue_sector;
	double	brightness;
	double	intermediate;
	double	remaining;
	int		rgb[3];

	hue_sector = current_hue / 60.0;
	remaining = hue_sector;
	while (remaining > 2.0)
		remaining -= 2.0;
	brightness = 0.9;
	intermediate = brightness * (1 - ft_abs_double(remaining - 1.0));
	colour_conversion(hue_sector, brightness, intermediate, rgb);
	parameters->screen->image_data[line * parameters->screen->window_size[0]
		+ col] = colour_in_int(rgb[0], rgb[1], rgb[2]);
}
