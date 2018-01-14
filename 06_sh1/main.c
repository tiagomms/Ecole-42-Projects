/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:57:56 by mbooth            #+#    #+#             */
/*   Updated: 2015/04/01 18:50:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			built_ins(char **split_line, char ***envp, int env_case,
			t_display *display)
{
	if (!ft_strcmp(split_line[0], "cd") && !env_case)
		ft_cd(split_line, envp);
	else if (!ft_strcmp(split_line[0], "env"))
		ft_env(split_line, *envp, display);
	else if (!ft_strcmp(split_line[0], "setenv") && !env_case)
		ft_setenv(split_line, envp, display);
	else if (!ft_strcmp(split_line[0], "unsetenv") && !env_case)
		ft_unsetenv(split_line, envp);
	else if (!ft_strcmp(split_line[0], "disp"))
		display->usr_n_pwd = 1;
	else if (!ft_strcmp(split_line[0], "undisp"))
		display->usr_n_pwd = 0;
	else if (!ft_strcmp(split_line[0], "exit") && !env_case)
	{
		ft_putstr("exit\n");
		change_shlvl(envp, -1);
		exit(0);
	}
	else
		return (0);
	return (1);
}

static void solve_conditions_of_line(char **split_line, char ***envp,
			t_display *display)
{
	if (is_minishell1(split_line[0], *envp))
		change_shlvl(envp, 1);
	if (split_line[0])
	{
		if (!built_ins(split_line, envp, 0, display))
		{
			if (!access(split_line[0], F_OK) && !access(split_line[0], X_OK))
				do_shell(split_line, *envp, 1, 0);
			else
				do_shell(split_line, *envp, 0, 0);
		}
	}
	if_disp_bonus(split_line, *envp, display);
}

static void	semi_colon_case(char *line, char **envp, t_display *display)
{
	char	**split_line;
	char	**semi_colon;
	int		i;

	semi_colon = ft_strsplit(line, ';');
	i = -1;
	while (semi_colon[++i])
	{
		split_line = custom_split(semi_colon[i], envp);
		solve_conditions_of_line(split_line, &envp, display);
		free_array(&split_line);
	}
	free_array(&semi_colon);
}

void		set_up_variables(int argc, char **argv, t_display *display,
					char **line)
{
	(void)argc;
	(void)argv;
	*line = NULL;
	ft_bzero(display, sizeof(*display));
	ft_putstr_fd("$> ", 1);
}

int			main(int argc, char **argv, char **ep)
{
	char		*line;
	char		**split_line;
	char		**envp;
	t_display	display;

	signal(SIGINT, ft_ctrlc);
	set_up_variables(argc, argv, &display, &line);
	envp = set_up_environment(&ep);
	change_shlvl(&envp, 1);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strchr(line, ';') != NULL)
		{
			semi_colon_case(line, envp, &display);
			ft_putstr_fd("$> ", 1);
			continue ;
		}
		split_line = custom_split(line, envp);
		solve_conditions_of_line(split_line, &envp, &display);
		free_array(&split_line);
		ft_putstr_fd("$> ", 1);
	}
	return (0);
}
