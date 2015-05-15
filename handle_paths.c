/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:40:27 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/21 20:15:40 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*find_path(char *command, char *envp_path)
{
	char	**split_dots;
	char	*temp;
	int		counter;
	char	*check;

	split_dots = ft_strsplit(envp_path, ':');
	if (!split_dots)
		return (NULL);
	temp = split_dots[0];
	split_dots[0] = ft_strchr(split_dots[0], '/');
	counter = -1;
	while (split_dots[++counter] != NULL)
	{
		check = ft_strjoin(ft_strjoin(split_dots[counter], "/"), command);
		if (!access(check, F_OK) && !access(check, X_OK))
		{
			split_dots[0] = temp;
			free_array(&split_dots);
			return (check);
		}
		free(check);
	}
	split_dots[0] = temp;
	free_array(&split_dots);
	return (NULL);
}
