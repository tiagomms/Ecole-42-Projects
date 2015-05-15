/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:06:06 by mbooth            #+#    #+#             */
/*   Updated: 2015/04/01 18:35:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		ft_unsetenv(char **split_line, char ***envp)
{
	char	**ep;
	size_t	i;

	ep = *envp;
	if (size_array(split_line) == 1)
		return (ft_putstr_fd("unsetenv: too few arguments\n", 2));
	i = 1;
	while (split_line[i])
	{
		remove_parameter_array(ep, find_str_in_array(ep, split_line[i]));
		i++;
	}
}

void		ft_setenv(char **split_line, char ***envp, t_display *display)
{
	char	*new_env_par;
	char	*temp;
	size_t	pos;

	if (size_array(split_line) == 1)
		return (ft_env(split_line, *envp, display));
	if (size_array(split_line) > 2)
		return (ft_putstr_fd("setenv: too many arguments\n", 2));
	if (split_line[1][0] == '=')
		return (ft_putstr_fd("setenv: syntax error\n", 2));
	if (!ft_strchr(split_line[1], '='))
	{
		temp = ft_strjoin(split_line[1], "=");
		free(split_line[1]);
		split_line[1] = temp;
	}
	new_env_par = ft_strdup(split_line[1]);
	pos = find_str_in_array(*envp, ft_str_until_chr(split_line[1], '='));
	if (pos != size_array(*envp))
		modify_in_array(envp, new_env_par, pos);
	else
		*envp = add_to_array(envp, new_env_par);
}

static void	env_print_variables(char **split_line_i, char ***dupl,
			t_display *display)
{
	if (!split_line_i)
		ft_putstr_fd("$> ", 1);
	else if (built_ins(split_line_i, dupl, 1, display))
		ft_putstr("");
	else if (!access(*split_line_i, F_OK) && !access(*split_line_i, X_OK))
		do_shell(split_line_i, *dupl, 1, 1);
	else
		do_shell(split_line_i, *dupl, 0, 1);
}

static void	env_with_parameters_case(char **split_line, char ***dupl,
			t_display *display)
{
	int		i;
	char	*new_env_par;
	size_t	pos;
	char	**restof_split_line;

	i = 0;
	while (split_line[++i] != NULL)
	{
		if (ft_strchr(split_line[i], '=') != NULL)
		{
			new_env_par = split_line[i];
			pos = find_str_in_array(*dupl,
					ft_str_until_chr(split_line[i], '='));
			if (pos != size_array(*dupl))
				modify_in_array(dupl, new_env_par, pos);
			else
				*dupl = add_to_array(dupl, new_env_par);
			continue ;
		}
		else
		{
			restof_split_line = split_line + i;
			return (env_print_variables(restof_split_line, dupl, display));
		}
	}
}

void		ft_env(char **split_line, char **envp, t_display *display)
{
	int		i;
	char	**dupl;

	dupl = ft_arraydup(envp);
	if (size_array(split_line) >= 2)
		return (env_with_parameters_case(split_line, &dupl, display));
	i = 0;
	while (dupl[i] != NULL)
	{
		ft_putstr(dupl[i]);
		ft_putchar('\n');
		i++;
	}
	free_array(&dupl);
}
