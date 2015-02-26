/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:24:57 by mbooth            #+#    #+#             */
/*   Updated: 2014/11/19 23:08:55 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = (-n);
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	if (n >= 0 && n <= 9)
		size++;
	return (size);
}

char	*ft_pos_itoa(char *str, int n, int size)
{
	str[size] = ((n % 10) + '0');
	n = n / 10;
	size--;
	while (n != 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_neg_itoa(char *str, int n, int size)
{
	str[size] = '0' - (n % 10);
	n = n / 10;
	size--;
	while (n != 0)
	{
		str[size] = '0' - (n % 10);
		n = n / 10;
		size--;
	}
	str[size] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_find_size(n);
	str = ft_strnew(size);
	size = size - 1;
	if (n >= 0)
		return (ft_pos_itoa(str, n, size));
	else
		return (ft_neg_itoa(str, n, size));
}
