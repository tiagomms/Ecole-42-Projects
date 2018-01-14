/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:59:57 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/27 11:13:24 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int	handle_errors_shell(char **split_line, int env_case)
{
	if (env_case)
	{
		ft_put2strs_fd("env: ", *split_line, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else
	{
		ft_putstr_fd("sh1: command not found: ", 2);
		ft_put2strs_fd(split_line[0], "\n", 2);
	}
	return (0);
}

static int	execute_str(char *str, char **split_line, char **envp)
{
	if (execve(str, split_line, envp) == -1)
		exit (0);
	return (1);
}

int			do_shell(char **split_line,
				char **envp, int full_path, int env_case)
{
	pid_t	child_pid;
	int		status;
	char	*path;

	if (!full_path)
	{
		path = find_path(split_line[0], envp[find_str_in_array(envp, "PATH")]);
		if (!path)
			return (handle_errors_shell(split_line, env_case));
	}
	child_pid = fork();
	if (child_pid >= 0)
	{
		if (child_pid == 0 && !full_path)
			return (execute_str(path, split_line, envp));
		else if (child_pid == 0 && full_path)
			return (execute_str(split_line[0], split_line, envp));
		else
		{
			wait(&status);
			return (0);
		}
	}
	return (0);
}
