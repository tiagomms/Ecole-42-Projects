/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 21:13:24 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 20:36:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include "./libft/includes/get_next_line.h"

typedef struct		s_info
{
	void			*start;
	void			*window;
	int				winsize[2];
	size_t			nbr_lines;
	size_t			nbr_cols_max;
	int				min_mid_max[3];
}					t_info;

typedef struct		s_image
{
	void			*img;
	unsigned int	*img_data;
	int				imgsize[2];
	int				bits_p_pxl;
	int				size_line;
	int				endian;
	int				i_pos[2];
	double			ratio[2];
	double			img_slope;
	int				colors[3][3];
	double			color_slopes[2][3];
}					t_image;

typedef struct		s_params
{
	t_list			*list;
	t_info			*info;
	t_image			*image;
	t_list			*colorpos;
	int				keycode;
	int				keycode_2;
	size_t			current_coor[2];
	int				point_lin_col;
	int				dot;
}					t_params;

void				ft_min_max_nbr_list(t_list **list, t_info *nbr_limits);
size_t				ft_max_contentsize(t_list **pointer_of_list);
int					ft_return_errs(int code_error, char *function_with_error);
void				draw_isometric(t_params *par_iso, size_t x, size_t y,
		t_list *list);
void				draw_parallel(t_params *par_par, size_t x, size_t y,
		t_list *list);
t_image				ft_create_image(t_params *fdf);
void				ft_clear_image(t_params *to_be_cleared);
void				get_s_image_test(t_params *new_img, int keycode);
void				mlx_put_pixel_image(double *p[], t_params *h,
		int z1, int z2);
void				mlx(t_list *list_with_data, t_list *inserted_colors);
void				ft_insert_last_line(t_list **begin_list, char *line,
		int get_next_line, t_list **color_loc);
int					ft_color_42(double current_z, t_params *par, int line_col);
void				ft_color_slopes(t_params *clr_i);
void				ft_set_colors(t_params *parameters);
int					color_in_int(int r, int g, int b);
int					hex_2_decimal(char c);
double				ft_abs_d(double n);

#endif
