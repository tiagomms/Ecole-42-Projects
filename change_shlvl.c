/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:17:02 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 11:54:38 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			is_minishell1(char *shell, char **ep)
{
	int		yes;
	char	*s_path;
	char	*temp;

	yes = 0;
	if (!shell)
		return (0);
	if (shell[0] != '/')
		s_path = ft_strjoin(ft_strchr(ep[find_str_in_array(ep, "PWD")], '/'),
							shell);
	else
		s_path = ft_strdup(shell);
	if (!access(s_path, F_OK) && !access(s_path, X_OK))
	{
		temp = s_path;
		s_path = ft_strrchr(s_path, '/') + 1;
		if (!ft_strcmp(s_path, "ft_minishell1"))
			yes = 1;
		s_path = temp;
	}
	ft_strdel(&s_path);
	return (yes);
}

static int	get_shlvl(char **envp, size_t pos)
{
	return (ft_atoi(&(*(ft_strchr(envp[pos], '=') + 1))));
}

void		change_shlvl(char ***envp, int change_lvl)
{
	size_t	pos;
	char	*new_shlvl;
	int		new_lvl;

	pos = find_str_in_array(*envp, "SHLVL");
	if (pos != size_array(*envp))
	{
		new_lvl = get_shlvl(*envp, pos) + change_lvl;
		new_shlvl = ft_strjoin("SHLVL=", ft_itoa(new_lvl));
		modify_in_array(envp, new_shlvl, pos);
	}
}
