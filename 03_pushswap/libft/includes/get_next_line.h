/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 20:00:45 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/11 20:04:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"
# include <unistd.h>
# define BUFF_SIZE 1000
# define MAX_FD 100

int					get_next_line(int const fd, char **line);

#endif
