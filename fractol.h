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
# include <mlx.h>
# include <math.h>
# include <stdio.h>//

typedef char		t_bool;

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
	int				max_iterations;
	double			central_point[2];
	double			current_limits_x[2];
	double			current_limits_y[2];
	double			zoom;
	double			current_point[2];
	double			x_gradient;
	double			y_gradient;
	double			colour_gradient;
	t_bool			lock_activated;
}					t_info;

typedef struct		s_parameters
{
	t_fractype		fractype;
	t_info			*info;
	t_screen		*screen;
	t_bool			update;
}					t_parameters;

void				set_screen(t_screen *screen);
void				set_info(t_info *info, t_screen *screen);
int					custom_atoi(const char *str);
int					mouse_hook(int button, int x, int y,
					t_parameters *parameters);
int 				key_hook(int keycode, t_parameters *parameters);
int					expose_hook(t_parameters *parameters);
double				get_current_x0(t_parameters *parameters, int col);
double				get_current_y0(t_parameters *parameters, int line);
void				handle_fractol(t_parameters *parameters);
void				set_new_info(t_info *info, t_screen *screen);
int					loop_hook(t_parameters *parameters);
int					mouse_motion_hook(int x, int y, t_parameters *parameters);

#endif