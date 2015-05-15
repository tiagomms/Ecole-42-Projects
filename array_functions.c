/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 19:03:34 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/25 16:22:54 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	remove_parameter_array(char **array, size_t i)
{
	if (i == size_array(array))
		return ;
	free(array[i]);
	while (array[i + 1] != NULL)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = NULL;
}

size_t	size_array(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	free_array(char ***array)
{
	size_t	i;

	i = 0;
	if (!(*array) || !array)
		return ;
	while ((*array)[i] != NULL)
	{
		ft_strdel(&((*array)[i]));
		i++;
	}
	free(*array);
	*array = NULL;
}

char	**ft_arraydup(char **ep)
{
	size_t	i;
	size_t	counter;
	char	**new_envp;

	counter = 0;
	i = size_array(ep);
	new_envp = (char**)malloc(sizeof(char*) * (i + 1));
	while (counter < i)
	{
		new_envp[counter] = ft_strdup(ep[counter]);
		counter++;
	}
	new_envp[counter] = NULL;
	return (new_envp);
}
