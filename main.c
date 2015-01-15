/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:34:30 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 17:25:43 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			get_result;
	char		*line;
	t_list		*list_in_main;
	t_list		*color_location;

	if (argc < 2)
		return (ft_return_errs(1, "Lack of file -"));
	list_in_main = NULL;
	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_return_errs(-1, NULL));
	while ((get_result = get_next_line(fd, &line)) > 0)
		ft_insert_last_line(&list_in_main, line, get_result, &color_location);
	if (get_result == 0)
		ft_insert_last_line(&list_in_main, line, get_result, &color_location);
	if (get_result == -1)
		return (ft_return_errs(-1, NULL));
	if (close(fd) == -1)
		return (ft_return_errs(-3, NULL));
	mlx(list_in_main, color_location);
	return (0);
}
