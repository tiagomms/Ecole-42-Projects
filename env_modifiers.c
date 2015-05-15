/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 19:09:44 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/24 21:30:56 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*ft_str_until_chr(char *str, int c)
{
	size_t	i;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new_str = ft_strsub(str, 0, i);
	return (new_str);
}

size_t	find_str_in_array(char **envp, char *new_variable)
{
	size_t	i;
	char	*variable_in_envp;

	i = 0;
	while (envp[i])
	{
		variable_in_envp = ft_str_until_chr(envp[i], '=');
		if (!ft_strcmp(variable_in_envp, new_variable))
		{
			ft_strdel(&variable_in_envp);
			break ;
		}
		if (variable_in_envp)
			free(variable_in_envp);
		i++;
	}
	return (i);
}

void	modify_in_array(char ***ep, char *new_variable, size_t pos)
{
	char	**envp;

	envp = *ep;
	free(envp[pos]);
	envp[pos] = new_variable;
}

char	**add_to_array(char ***ep, char *new_string)
{
	int		i;
	int		counter;
	char	**new_envp;
	char	**envp;

	counter = 0;
	envp = *ep;
	i = size_array(envp);
	new_envp = (char**)malloc(sizeof(char*) * (i + 2));
	while (counter < i)
	{
		new_envp[counter] = ft_strdup(envp[counter]);
		ft_strdel(&envp[counter]);
		counter++;
	}
	new_envp[counter] = ft_strdup(new_string);
	new_envp[counter + 1] = NULL;
	free(envp);
	envp = NULL;
	return (new_envp);
}
