/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:20:47 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/09 23:28:21 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 1;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i - 1] == (unsigned char)s2[i - 1] &&
			s1[i - 1] != '\0' && i < n)
		i++;
	return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
}
