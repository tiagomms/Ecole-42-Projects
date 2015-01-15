/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:33:36 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 18:23:42 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fsp(char const *s, size_t i)
{
	if (s[i] != '\0' && (s[i] == 32 || s[i] == '\t' || s[i] == '\n'))
		return (ft_fsp(s, i + 1));
	return (i);
}

static size_t	ft_f_end(char const *s, size_t n)
{
	if (s[n] != '\t' && s[n] != '\n' && s[n] != 32 && s[n] != '\0')
		return (ft_f_end(s, n + 1));
	if (ft_fsp(s, n) == ft_strlen(s))
		return (n);
	return (ft_f_end(s, ft_fsp(s, n)));
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	size_t	start;
	size_t	end;

	start = ft_fsp(s, 0);
	end = ft_f_end(s, start);
	res = ft_strsub(s, (unsigned int)start, end - start);
	return (res);
}
