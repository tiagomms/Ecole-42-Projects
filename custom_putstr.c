/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:25:34 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 15:26:07 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_put2strs_fd(char *str1, char *str2, int fd)
{
	char *join;

	join = ft_strjoin(str1, str2);
	ft_putstr_fd(join, fd);
	free(join);
}
