/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 12:17:36 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/28 12:17:44 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_if(int boolean, char pos, char neg)
{
	if (boolean)
		ft_putchar(pos);
	else
		ft_putchar(neg);
}
