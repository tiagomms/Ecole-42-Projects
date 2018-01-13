/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:55:34 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/12 15:36:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] != '\0'
			&& i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i] == 0);
}
