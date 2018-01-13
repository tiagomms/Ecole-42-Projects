/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:41:35 by tsilva            #+#    #+#             */
/*   Updated: 2014/11/29 22:46:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs_fd(int n)
{
	return (n < 0 ? -n : n);
}

static void	ft_help_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_help_fd(n / 10, fd);
	ft_putchar_fd(ft_abs_fd(n % 10) + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_help_fd(n, fd);
}
