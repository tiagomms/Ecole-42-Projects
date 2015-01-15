/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:47:42 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/30 15:51:52 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_fndchar(char *s, unsigned char c)
{
	size_t	lim;

	lim = 0;
	if (s)
	{
		while (s[lim] != '\0' && s[lim] != c)
			lim++;
	}
	return (lim);
}

static char		*create_addbuffs(char *leftover)
{
	char	*addbuffs;

	if (leftover)
		addbuffs = ft_strdup(leftover);
	else
		addbuffs = ft_strnew(0);
	return (addbuffs);
}

static char		*form_leftover(char *addbuffs, char *new_leftover)
{
	if (ft_fndchar(addbuffs, '\n') != ft_fndchar(addbuffs, '\0'))
		new_leftover = ft_strdup(ft_strchr(addbuffs, '\n') + 1);
	else
		new_leftover = NULL;
	ft_strdel(&addbuffs);
	return (new_leftover);
}

int				get_next_line(int const fd, char **line)
{
	static char		*leftov[MAX_FD];
	char			*addbuffs;
	int				ret;
	char			b[BUFF_SIZE + 1];

	if (!line || fd < 0 || fd > MAX_FD - 1)
		return (-1);
	if (ft_fndchar(leftov[fd], '\n') != ft_fndchar(leftov[fd], '\0'))
	{
		*line = ft_strsub(leftov[fd], 0, ft_fndchar(leftov[fd], '\n'));
		leftov[fd] += ft_fndchar(leftov[fd], '\n') + 1;
		return (1);
	}
	addbuffs = create_addbuffs(leftov[fd]);
	while ((ret = read(fd, b, BUFF_SIZE)) > 0)
	{
		b[ret] = '\0';
		if (!(addbuffs = ft_strjoin(addbuffs, b)) ||
				ft_fndchar(addbuffs, '\n') != ft_fndchar(addbuffs, '\0'))
			break ;
	}
	if (ret == -1 || !(addbuffs))
		return (-1);
	*line = ft_strsub(addbuffs, 0, ft_fndchar(addbuffs, '\n'));
	return ((leftov[fd] = form_leftover(addbuffs, leftov[fd])) ? 1 : 0);
}
