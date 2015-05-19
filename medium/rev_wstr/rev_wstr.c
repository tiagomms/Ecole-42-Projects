/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 09:34:49 by exam              #+#    #+#             */
/*   Updated: 2015/05/13 09:57:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t		ft_strlen_m(char *str, char c)
{
	size_t len;

	len = 0;
	if (str)
	{
		while (str[len] && str[len] != c)
			len++;
	}
	return (len);
}

size_t		ft_rev_strlen_m(char *str, char c, size_t end)
{
	size_t start;

	start = end - 1;
	while (str[start] != c && start > 0)
		start--;
	return (str[start] == c ? ++start : start);
}

void		rev_wstr(char *str)
{
	size_t start;
	size_t end;

	end = ft_strlen_m(str, '\0');
	if (end != 0)
	{
		start = ft_rev_strlen_m(str, ' ', end);
		if (start != end)
		{
			while (start > 0)
			{
				write(1, &(str[start]), end - start);
				end = start - 1;
				start = ft_rev_strlen_m(str, ' ', end);
				write(1, " ", 1);
			}
			write(1, &(str[start]), end - start);
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		rev_wstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

