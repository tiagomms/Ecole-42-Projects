/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:58:36 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 15:57:26 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <dirent.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <sys/stat.h>
# define BUFFER_SIZE		1024

typedef struct	s_display
{
	int			usr_n_pwd;
}				t_display;

void			ft_setenv(char **split_line, char ***envp,
				t_display *display);
char			**custom_split(char const *s, char **envp);
void			ft_cd(char **split_line, char ***envp);
void			ft_env(char **split_line, char **envp, t_display *display);
char			**ft_arraydup(char **ep);
size_t			size_array(char **envp);
void			free_array(char ***array);
char			**ft_arraydup(char **ep);
char			**add_to_array(char ***ep, char *new_string);
void			remove_parameter_array(char **array, size_t i);
void			ft_unsetenv(char **split_line, char ***envp);
size_t			find_str_in_array(char **envp, char *new_variable);
void			modify_in_array(char ***ep, char *new_variable, size_t pos);
char			**set_up_environment(char ***envp);
char			*ft_str_until_chr(char *str, int c);
int				built_ins(char **split_line, char ***envp,
				int env_case, t_display *display);
int				do_shell(char **split_line,
				char **envp, int full_path, int env_case);
void			ft_put2strs_fd(char *str1, char *str2, int fd);
void			change_shlvl(char ***envp, int change_lvl);
char			*find_path(char *command, char *envp_path);
int				is_minishell1(char *shell, char **ep);
void			if_disp_bonus(char **split_line, char **envp,
					t_display *display);
int				do_shell(char **split_line, char **envp,
				int full_path, int env_case);
void			ft_put2strs_fd(char *str1, char *str2, int fd);
void			ft_ctrlc(int ignore);

#endif
