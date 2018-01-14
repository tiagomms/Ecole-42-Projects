/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 18:28:44 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 10:11:37 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		home_insideof_pwd(char *pwd, char *home)
{
	size_t	i;
	size_t	len_pwd;
	size_t	len_home;

	i = 0;
	len_pwd = ft_strlen(pwd);
	len_home = ft_strlen(home);
	if (len_pwd < len_home)
		return (-1);
	while (i < len_pwd - len_home)
	{
		if (!ft_strncmp(&(pwd[i]), home, len_home))
			break ;
		i++;
	}
	if (i == len_pwd - len_home)
		return (-1);
	else
		return (i);
}

char	*home_in_pwd(char **envp, size_t pos_pwd)
{
	size_t	pos_home;
	char	*pwd;
	char	*home;
	int		i;

	pos_home = find_str_in_array(envp, "HOME");
	pwd = ft_strchr(envp[pos_pwd], '/');
	if (find_str_in_array(envp, "HOME") == size_array(envp))
		return (pwd);
	home = ft_strchr(envp[pos_home], '/');
	if ((i = home_insideof_pwd(pwd, home)) != -1)
	{
		ft_putchar('~');
		return (&(*(pwd + (size_t)i + ft_strlen(home))));
	}
	else
		return (pwd);
}

void	if_disp_bonus(char **split_line, char **envp, t_display *display)
{
	char	hostname[255];
	char	*host;
	size_t	pos_usr;
	size_t	pos_pwd;

	if (!display->usr_n_pwd || !split_line)
		return ;
	if ((pos_usr = find_str_in_array(envp, "USER")) == size_array(envp))
		return ;
	if ((pos_pwd = find_str_in_array(envp, "PWD")) == size_array(envp))
		return ;
	gethostname(hostname, sizeof(hostname));
	ft_putstr(ft_strchr(envp[pos_usr], '=') + 1);
	host = ft_str_until_chr(hostname, '.');
	ft_put2strs_fd("@", host, 1);
	ft_strdel(&host);
	ft_putchar(':');
	ft_put2strs_fd(home_in_pwd(envp, pos_pwd), "\n", 1);
}
