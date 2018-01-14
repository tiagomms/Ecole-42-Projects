/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:30:19 by exam              #+#    #+#             */
/*   Updated: 2015/05/13 11:40:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t		ft_strlen(char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

char		*ft_strsub(char *str, size_t start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = malloc(sizeof(char) * (len + 1));
	substr[len] = '\0';
	i = 0;
	while (i < len)
	{
		substr[i] = str[i + start];
		i++;
	}
	return (substr);
}

int			is_within_str(char *substr, size_t pos, char *current_str, size_t start)
{
	if (substr[pos] == '\0')
		return (1);
	if (ft_strlen(substr) - pos > ft_strlen(current_str) - start)
		return (0);
	if (substr[pos] == current_str[start])
		return ((is_within_str(substr, pos + 1, current_str, start + 1) ||
				 is_within_str(substr, 0, current_str, start + 1)));
	else
		return (is_within_str(substr, 0, current_str, start + 1));
}

char		*str_maxlenoc(char *comp_str, size_t sub_start, size_t sub_len, char **argv, int current_argv)
{
	char		*substr;

	if (sub_len == 0)
		return ("");
	if (sub_start + sub_len > ft_strlen(argv[1]))
		return (str_maxlenoc(comp_str, 0, sub_len - 1, argv, 2));
	substr = ft_strsub(comp_str, sub_start, sub_len);
	if (!argv[current_argv])
		return (substr);
	if (is_within_str(substr, 0, argv[current_argv], 0))
	{
		free(substr);
		return (str_maxlenoc(comp_str, sub_start, sub_len, argv, current_argv + 1));
	}
	else
	{
		free(substr);
		return (str_maxlenoc(comp_str, sub_start + 1, sub_len, argv, 2));		
	}
}

int			main(int argc, char **argv)
{
	char *str_max;

	if (argc != 1)
	{
		str_max = str_maxlenoc(argv[1], 0, ft_strlen(argv[1]), argv, 2);
		write(1, str_max, ft_strlen(str_max));
	}
	write(1, "\n", 1);
	return (0);
}
