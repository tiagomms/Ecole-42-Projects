/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 18:28:22 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/12 20:01:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	ft_add(int n1, int n2, int *prev_result, char *final_nbr)
{
	int result;

	result = 0;
	if ((*prev_result) / 10 > 0)
		result++;
	result += n1 + n2;
	insert_digit(result % 10, final_nbr);
	*prev_result = result;
}

t_bool	if_continue_add(char *n2, int pos2, int pos1)
{
	int check2;

	check2 = (pos2 >= 0 && n2[pos2] != '-');
	return (check2 && pos1 >= 0);
}

void	infin_add_mod(char **totalptr, int starting_total_pos, char *new_value)
{
	int		pos1;
	int		pos2;
	char	*total;
	int		prev_result;

	total = *totalptr;
	pos1 = ft_strlen(total) - starting_total_pos;
	total += pos1;
	pos2 = ft_strlen(new_value) - 1;
	prev_result = 0;
	while (if_continue_add(new_value, pos2, pos1))
	{
		total--;
		ft_add((*total - '0'), get_digit(new_value, pos2), &prev_result, total);
		pos1--;
		pos2--;
	}
}
