/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 09:17:30 by mbooth            #+#    #+#             */
/*   Updated: 2015/02/14 13:59:03 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str_to_be_reversed)
{
	char	temp_char;
	size_t	len;
	size_t	i;
	char	*str_reversed;

	str_reversed = (char*)str_to_be_reversed;
	if (!str_reversed || ft_strlen(str_reversed) == 0)
		return (str_reversed);
	i = 0;
	len = ft_strlen(str_reversed) - 1;
	while (i < len)
	{
		temp_char = str_reversed[i];
		str_reversed[i++] = str_reversed[len];
		str_reversed[len--] = temp_char;
	}
	return (str_reversed);
}
