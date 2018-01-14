/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:59:12 by mbooth            #+#    #+#             */
/*   Updated: 2015/03/26 10:09:00 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int	ft_count_words(char const *s)
{
	int		i;
	int		state;
	int		word_counter;

	state = 0;
	i = 0;
	word_counter = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && state == 0)
		{
			state = 1;
			word_counter++;
		}
		if ((s[i] == ' ' || s[i] == '\t') && state == 1)
			state = 0;
		i++;
	}
	return (word_counter);
}

static char *solve_til_case(char const *s, int start, char **envp, int i)
{
	char	*til_case;
	size_t	pos;
	char	*str_with_til;

	if (s[start] == '~' &&
		(pos = find_str_in_array(envp, "HOME")) != size_array(envp))
	{
		til_case = ft_strchr(envp[pos], '/');
		start++;
	}
	else
		til_case = "";
	str_with_til = ft_strjoin(til_case, ft_strsub(s, start, (i - start)));
	return (str_with_til);
}

static void	ft_word_pointers(char **array, char const *s, char **envp)
{
	int		i;
	int		state;
	int		start;

	start = 0;
	i = 0;
	state = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && state == 0)
		{
			start = i;
			state = 1;
		}
		else if ((s[i] == ' ' || s[i] == '\t') && state == 1)
		{
			state = 0;
			*array = solve_til_case(s, start, envp, i);
			array++;
		}
		i++;
	}
	if (state == 1)
		*array = solve_til_case(s, start, envp, i);
}

char		**custom_split(char const *s, char **envp)
{
	char	**array;
	int		nb;

	if (!s)
		return (0);
	nb = ft_count_words(s);
	array = (char **)malloc(sizeof(char*) * (nb + 1));
	if (!array)
		return (NULL);
	ft_word_pointers(array, s, envp);
	array[nb] = NULL;
	return (array);
}
