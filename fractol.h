/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:52:59 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/25 17:17:39 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"

typedef enum		e_fractype
{
	JULIA, MANDELBROT, OTHER
}					t_fractype;

typedef	struct		s_screen
{
	void			*mlx_ptr;
	void			*window;
	void			*image_ptr;
	int				window_size[2];
	unsigned int	*image_data;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
}					t_screen;

typedef struct		s_info
{
	int				iterations;
	double			central_point[2];.
	double			current_limits_x[2];
	double			current_limits_y[2];
	int				zoom;
	double			current_point[2];
	double			x_gradient;
	double			y_gradient;
}					t_info;

typedef struct		s_parameters
{
	t_fractype		*fractype;
	t_info			*info;
	t_screen		*screen;
}					t_parameters;