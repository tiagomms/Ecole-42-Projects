/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 19:12:55 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/12 20:16:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	ft_mult(int n1, int n2, int *prev_result, char *final_nbr, int pos)
{
	int result;

	result = (*prev_result) / 10;
	result += (n1 * n2);
	final_nbr[pos] = (result % 10) + '0';
	*prev_result = result;
}

char	*infin_mult(char *n1, char *n2)
{
	char	*total;
	char	new_value[MAX_SIZE - 2];
	int		prev_result;
	int		pos1;
	int		pos2;
	int		pos_new_value;

	total = malloc(sizeof(char) * (MAX_SIZE + 1));
	ft_bcharzero(total, MAX_SIZE);
	pos2 = ft_strlen(n2) - 1;
	while (pos2 >= 0 && n2[pos2] != '-')
	{
		ft_bcharzero(new_value, MAX_SIZE - 2);
		pos_new_value = MAX_SIZE - 2;
		prev_result = 0;
		pos1 = ft_strlen(n1) - 1;
		while (pos1 >= 0 && n1[pos1] != '-')
		{
			pos_new_value--;
			ft_mult(get_digit(n1, pos1), get_digit(n2, pos2), &prev_result, new_value, pos_new_value);
			pos1--;
		}
		infin_add_mod(&total, ft_strlen(n2) - 1 - pos2, new_value);
		pos2--;
	}
	remove_initial_zeros(&total);
	if (prev_result / 10 != 0)
	{
		total--;
		*total = (prev_result % 10) + '0';
		prev_result /= 10;
		total--;
		*total = (prev_result % 10) + '0';
	}
	if ((is_neg(n1) && !is_neg(n2)) ||
		(!is_neg(n1) && is_neg(n2)))
	{
		total--;
		*total = '-';
	}
	return (total);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_putstr(infin_mult(argv[1], argv[2]));
	ft_putstr("\n");
}
