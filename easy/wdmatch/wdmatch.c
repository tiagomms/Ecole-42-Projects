/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 09:26:36 by exam              #+#    #+#             */
/*   Updated: 2015/05/13 09:31:40 by exam             ###   ########.fr       */
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

int			wdmatch(char *str1, char *str2)
{
	size_t i1;
	size_t i2;

	i1 = 0;
	i2 = 0;
	while (str1[i1] && str2[i2])
	{
		if (str1[i1] == str2[i2])
			i1++;
		i2++;
	}
	return (str1[i1] == '\0');
}

int			main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (wdmatch(argv[1], argv[2]))
			write(1, argv[1], ft_strlen(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
