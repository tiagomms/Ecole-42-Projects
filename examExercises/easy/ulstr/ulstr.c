/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 09:17:17 by exam              #+#    #+#             */
/*   Updated: 2015/05/13 09:22:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

char		*ulstr(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		write(1, ulstr(argv[1]), ft_strlen(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
