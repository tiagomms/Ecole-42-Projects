/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 18:30:45 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/12 18:38:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	write (1, str, (size_t)ft_strlen(str));
}

t_bool	is_neg(char *nbr)
{
	return (nbr[0] == '-');
}

int		get_digit(char *n, int pos)
{
	if (pos < 0 || n[pos] == '-')
		return (0);
	return (n[pos] - '0');
}

void	insert_digit(int digit, char *final_nbr)
{
	*final_nbr = digit + '0';
}

void	ft_bcharzero(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
}

void	remove_initial_zeros(char **final_res_ptr)
{
	char *final_res;

	final_res = *final_res_ptr;
	while (*final_res && *final_res == '0')
		final_res++;
	if (!(*final_res))
		final_res--;
	*final_res_ptr = final_res;
}
