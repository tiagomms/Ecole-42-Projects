/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:16:43 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/16 19:08:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrwrd(char const *s, char c, size_t w)
{
	size_t	aux;

	if (s[w] == '\0')
		return (0);
	if (s[w] == c)
		return (ft_nbrwrd(s, c, 1 + w));
	aux = w;
	while (s[aux] != c && s[aux] != '\0')
		aux++;
	return (1 + ft_nbrwrd(s, c, aux));
}

static size_t	ft_fndstr(char const *s, char c, size_t start)
{
	if (s[start] == '\0' || s[start] != c)
		return (start);
	return (ft_fndstr(s, c, 1 + start));
}

static size_t	ft_fndend(char const *s, char c, size_t end)
{
	if (s[end] == '\0' || s[end] == c)
		return (end);
	return (ft_fndend(s, c, 1 + end));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	wrd;
	size_t	n_wrd;
	size_t	start;
	size_t	end;

	n_wrd = ft_nbrwrd(s, c, 0);
	if (!(res = (char**)malloc(sizeof(char*) * (n_wrd + 1))))
		return (NULL);
	wrd = 0;
	start = ft_fndstr(s, c, 0);
	while (wrd++ < n_wrd && s[start] != '\0')
	{
		end = ft_fndend(s, c, start);
		res[wrd - 1] = ft_strsub(s, (unsigned int)start, end - start);
		start = ft_fndstr(s, c, end);
	}
	res[wrd - 1] = '\0';
	return (res);
}
