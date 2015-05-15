/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:50:14 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 16:07:06 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char	**create_environment(void)
{
	char	**envp;
	char	buf[BUFFER_SIZE];

	envp = (char**)malloc(sizeof(char*) * 4);
	getcwd(buf, BUFFER_SIZE);
	envp[0] = ft_strjoin("PWD=", buf);
	envp[1] = ft_strdup("SHLVL=1");
	envp[2] = ft_strjoin("_=", ft_strjoin(buf, "/./ft_minishell1"));
	envp[3] = NULL;
	return (envp);
}

char		**set_up_environment(char ***ep)
{
	size_t	pos_pwd;
	size_t	pos_shlvl;
	size_t	pos_exec;
	char	**envp;
	char	buf[BUFFER_SIZE];

	if (!ep || !*ep)
		return (create_environment());
	envp = ft_arraydup(*ep);
	pos_pwd = find_str_in_array(envp, "PWD");
	if (pos_pwd != size_array(envp) &&
		find_str_in_array(envp, "SHLVL") != size_array(envp) &&
		find_str_in_array(envp, "_") != size_array(envp))
		return (envp);
	getcwd(buf, BUFFER_SIZE);
	if (pos_pwd == size_array(envp))
		envp = add_to_array(&envp, ft_strjoin("PWD=", buf));
	pos_shlvl = find_str_in_array(envp, "SHLVL");
	if (pos_shlvl == size_array(envp))
		envp = add_to_array(&envp, ft_strdup("SHLVL=1"));
	pos_exec = find_str_in_array(envp, "_");
	if (pos_exec == size_array(envp))
		envp = add_to_array(&envp, ft_strjoin("_=",
				ft_strjoin(buf, "/./ft_minishell1")));
	return (envp);
}
