/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:39:04 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 15:26:01 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void	go_back_last_directory(char ***envp)
{
	size_t	pos_pwd;
	char	*str_pwd;
	size_t	pos_oldpwd;
	char	*str_oldpwd;

	pos_oldpwd = find_str_in_array(*envp, "OLDPWD");
	if (pos_oldpwd != size_array(*envp))
	{
		pos_pwd = find_str_in_array(*envp, "PWD");
		str_pwd = ft_strdup(ft_strchr((*envp)[pos_oldpwd], 'P'));
		str_oldpwd = ft_strjoin("OLD", (*envp)[pos_pwd]);
		chdir(ft_strchr((*envp)[pos_oldpwd], '/'));
		modify_in_array(envp, str_pwd, pos_pwd);
		modify_in_array(envp, str_oldpwd, pos_oldpwd);
	}
}

static void	handle_new_directory(char **split_line, char ***envp, char *buf)
{
	char		buf_new_dir[BUFFER_SIZE];
	char		*new_directory;
	char		*old_directory;
	size_t		pos;

	old_directory = ft_strjoin("OLDPWD=", buf);
	if ((pos = find_str_in_array(*envp, "OLDPWD")) != size_array(*envp))
		modify_in_array(envp, old_directory, pos);
	else
		*envp = add_to_array(envp, old_directory);
	if (split_line[1][0] == '/')
		new_directory = ft_strdup(split_line[1]);
	else
		new_directory = ft_strjoin(ft_strjoin(buf, "/"), split_line[1]);
	chdir(new_directory);
	getcwd(buf_new_dir, BUFFER_SIZE);
	free(new_directory);
	new_directory = ft_strjoin("PWD=", buf_new_dir);
	modify_in_array(envp, new_directory, find_str_in_array(*envp, "PWD"));
}

static void just_cd_case(char ***envp, char *buf)
{
	char	*old_directory;
	char	*home_directory;
	char	*pwd_directory;
	size_t	pos_home;

	if ((pos_home = find_str_in_array(*envp, "HOME")) == size_array(*envp))
		return (ft_putstr_fd("cd: no home directory\n", 2));
	home_directory = ft_strchr((*envp)[pos_home], '/');
	chdir(home_directory);
	pwd_directory = ft_strjoin("PWD=", home_directory);
	modify_in_array(envp, pwd_directory, find_str_in_array(*envp, "PWD"));
	old_directory = ft_strjoin("OLDPWD=", buf);
	if ((pos_home = find_str_in_array(*envp, "OLDPWD")) != size_array(*envp))
		modify_in_array(envp, old_directory, pos_home);
	else
		*envp = add_to_array(envp, old_directory);
}

static void	edge_cases(char **split_line, char ***envp, char *buf)
{
	if (size_array(split_line) == 1)
		return (just_cd_case(envp, buf));
	return (ft_putstr_fd("cd : too many arguments\n", 2));
}

void		ft_cd(char **split_line, char ***envp)
{
	char		buf[BUFFER_SIZE];
	DIR			*direct;
	struct stat	*stats;
	int			to_last_directory;

	getcwd(buf, BUFFER_SIZE);
	stats = NULL;
	if ((size_array(split_line) == 1 || size_array(split_line) >= 3))
		return (edge_cases(split_line, envp, buf));
	direct = opendir(split_line[1]);
	to_last_directory = (ft_strcmp(split_line[1], "-") == 0);
	if (!to_last_directory && !direct)
	{
		if (!lstat(split_line[1], stats) || !stat(split_line[1], stats))
			ft_putstr_fd("cd : not a directory: ", 2);
		else
			ft_putstr_fd("cd: no such file or directory: ", 2);
		return (ft_put2strs_fd(split_line[1], "\n", 2));
	}
	if (to_last_directory)
		go_back_last_directory(envp);
	else
		handle_new_directory(split_line, envp, buf);
	if (direct)
		(void)closedir(direct);
}
