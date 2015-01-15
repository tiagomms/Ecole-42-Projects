/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:06:49 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/24 21:04:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

static void	ft_help(int n)
{
	if (n >= 10 || n <= -10)
		ft_help(n / 10);
	ft_putchar(ft_abs(n % 10) + 48);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_help(n);
}
