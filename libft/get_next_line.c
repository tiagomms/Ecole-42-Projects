/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 21:57:01 by mbooth            #+#    #+#             */
/*   Updated: 2014/12/05 16:16:07 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*nextlinesplit(char *buffer, char **leftover)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			j = ft_strlen(buffer);
			if (j != i)
				*leftover = ft_strsub(buffer, i + 1, (j - i - 1));
			return (s = ft_strsub(buffer, 0, i));
		}
		i++;
	}
	return (NULL);
}

char	*findbuffer(char *leftover, char *tempbuff)
{
	char	*buffer;
	int		length;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!leftover)
		length = 0;
	else
		length = ft_strlen(leftover);
	buffer = ft_strnew(BUFF_SIZE + length);
	while (i < length)
	{
		buffer[i] = leftover[i];
		i++;
	}
	while (l < BUFF_SIZE)
	{
		buffer[i] = tempbuff[l];
		i++;
		l++;
	}
	buffer[i] = '\0';
	return (buffer);
}

int		check_leftover(char **leftover, char **line)
{
	int		i;
	int		length;
	char	*buff;

	i = 0;
	if (leftover[0])
		length = ft_strlen(leftover[0]);
	while (i < length && leftover[0])
	{
		if (leftover[0][i] == '\n')
		{
			buff = ft_strdup(leftover[0]);
			*line = nextlinesplit(buff, &leftover[0]);
			free(buff);
			return (1);
		}
		i++;
	}
	return (0);
}

int		returnthis(int ret, char **line)
{
	if (ret == 0 || ret == -1)
	{
		*line = NULL;
		return (ret);
	}
	else
		return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char *leftover;
	char		tempbuff[BUFF_SIZE + 1];
	char		*buff;
	int			ret;

	if (!line)
		return (-1);
	if ((ret = check_leftover(&leftover, line)) == 1)
		return (1);
	while ((ret = read(fd, tempbuff, BUFF_SIZE)) >= 0)
	{
		tempbuff[ret] = '\0';
		buff = findbuffer(leftover, tempbuff);
		leftover = NULL;
		if ((*line = nextlinesplit(buff, &leftover)) != NULL)
			break ;
		if (ret < BUFF_SIZE)
		{
			*line = ft_strdup(buff);
			return (0);
		}
		leftover = ft_strdup(buff);
	}
	return (returnthis(ret, line));
}
