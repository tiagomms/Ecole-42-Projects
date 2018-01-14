/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_initial_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:52:52 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/10 23:04:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_arraylen(char **line_split)
{
	size_t	columns_in_line;

	columns_in_line = 0;
	if (line_split)
	{
		while (line_split[columns_in_line])
			columns_in_line++;
	}
	return (columns_in_line);
}

static int		get_char_hex(char *hex_number)
{
	char	**split_0x_rest;
	int		*red_gr_blue;
	int		color_int;
	int		j;

	if (ft_arraylen((split_0x_rest = ft_strsplit(hex_number, 'x'))) != 2)
		return (-1);
	if (ft_strlen(split_0x_rest[1]) != 6)
	{
		ft_return_errs(0, "Invalid hexadecimal code attached to a z");
		exit(0);
	}
	red_gr_blue = (int*)ft_memalloc(sizeof(int) * 3);
	j = -1;
	while (++j < 3)
		red_gr_blue[j] = hex_2_decimal(split_0x_rest[1][(2 * j)])
				* 16 + hex_2_decimal(split_0x_rest[1][2 * j + 1]);
	color_int = color_in_int(red_gr_blue[0], red_gr_blue[1], red_gr_blue[2]);
	j = 0;
	while (split_0x_rest[j])
		free(split_0x_rest[j++]);
	free(split_0x_rest);
	split_0x_rest = NULL;
	ft_memdel((void**)&red_gr_blue);
	return (color_int);
}

static void		get_color_location(char **line_split, int line,
		t_list **color_loc)
{
	int		j;
	int		*y_x_color;
	int		color_res;

	j = 0;
	while (line_split[j])
	{
		if ((ft_strcmp(ft_itoa(ft_atoi(line_split[j])), line_split[j]) != 0)
				&& ((color_res = get_char_hex(line_split[j])) != -1))
		{
			y_x_color = (int*)malloc(sizeof(int) * 3);
			y_x_color[0] = line;
			y_x_color[1] = j;
			y_x_color[2] = color_res;
			ft_lst_pushback(color_loc, y_x_color, 3);
		}
		j++;
	}
}

static int		*get_line_nbrs(char **line_split, size_t line_length)
{
	int		*line_nbrs;
	size_t	i;

	if (!line_split)
		return (0);
	if (line_length)
	{
		line_nbrs = (int *)malloc(sizeof(int) * line_length);
		i = 0;
		while (line_split[i])
		{
			line_nbrs[i] = ft_atoi(line_split[i]);
			free(line_split[i]);
			line_split[i] = NULL;
			i++;
		}
	}
	else
		line_nbrs = 0;
	free(line_split);
	line_split = NULL;
	return (line_nbrs);
}

void			ft_insert_last_line(t_list **initial_line, char *line_from_get,
		int value_from_gnl, t_list **color_loc)
{
	char		**line_split;
	size_t		length;
	int			*line_nbrs;
	static int	line = 0;

	if (ft_strlen(line_from_get) == 0 && value_from_gnl == 1)
	{
		ft_return_errs(-4, NULL);
		exit(0);
	}
	if (ft_strlen(line_from_get) == 0)
		return ;
	line_split = ft_strsplit(line_from_get, ' ');
	length = ft_arraylen(line_split);
	get_color_location(line_split, line, color_loc);
	if ((line_nbrs = get_line_nbrs(line_split, length)))
		ft_lst_pushback(initial_line, line_nbrs, length);
	free(line_from_get);
	line_from_get = NULL;
	line++;
}
