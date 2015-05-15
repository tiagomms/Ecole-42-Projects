/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 22:04:09 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/19 23:33:52 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		state;
	int		word_counter;

	state = 0;
	i = 0;
	word_counter = 0;
	while (s[i])
	{
		if (s[i] != c && state == 0)
		{
			state = 1;
			word_counter++;
		}
		if (s[i] == c && state == 1)
			state = 0;
		i++;
	}
	return (word_counter);
}

static void	ft_word_pointers(char **array, char const *s, char c)
{
	int		i;
	int		state;
	int		start;

	start = 0;
	i = 0;
	state = 0;
	while (s[i])
	{
		if (s[i] != c && state == 0)
		{
			start = i;
			state = 1;
		}
		else if (s[i] == c && state == 1)
		{
			state = 0;
			*array = ft_strsub(s, start, (i - start));
			array++;
		}
		i++;
	}
	if (state == 1)
		*array = ft_strsub(s, start, (i - start));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		nb;

	if (!s || !c)
		return (0);
	nb = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char*) * (nb + 1));
	if (!array)
		return (NULL);
	ft_word_pointers(array, s, c);
	array[nb] = NULL;
	return (array);
}
