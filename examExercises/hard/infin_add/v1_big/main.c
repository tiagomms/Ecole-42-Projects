/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:30:41 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/12 19:16:29 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

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

t_bool	add_or_sub(char *n1, char *n2)
{
	if ((!is_neg(n1) && !is_neg(n2)) ||
		(is_neg(n1) && is_neg(n2)))
		return (0);
	return (1);
}

t_bool	is_n2_biggest_nbr(char *n1, char *n2)
{
	int	len_n1;
	int len_n2;
	int	is_neg_n1;
	int is_neg_n2;

	is_neg_n1 = is_neg(n1);
	is_neg_n2 = is_neg(n2);
	len_n1 = ft_strlen(n1) - is_neg_n1;
	len_n2 = ft_strlen(n2) - is_neg_n2;
	if (len_n1 > len_n2)
		return (0);
	if (len_n2 > len_n1)
		return (1);
	while (n2[is_neg_n2] == n1[is_neg_n1])
	{
		is_neg_n1++;
		is_neg_n2++;
	}
	return (n2[is_neg_n2] > n1[is_neg_n1]);
}


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

void	ft_sub(int n1, int n2, int *prev_result, char *final_nbr)
{
	int result;

	if ((*prev_result) / 10 > 0)
		n1++;
	if (n2 - n1 < 0)
		n2 += 10;
	result = n2 - n1;
	*prev_result = n2;
	insert_digit(result % 10, final_nbr);
}

t_bool	if_continue_add(char *n1, char *n2, int pos1, int pos2)
{
	int check1;
	int check2;

	check1 = (pos1 >= 0 && n1[pos1] != '-');
	check2 = (pos2 >= 0 && n2[pos2] != '-');
	return (check1 || check2);
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

char	*infin_add(char *n1, char *n2)
{
	int		pos1;
	int		pos2;
	char 	*final_res;
	int		prev_result;

	final_res = malloc(sizeof(char) * (MAX_SIZE + 1));
	final_res += MAX_SIZE;
	(*final_res) = '\0';
	pos1 = ft_strlen(n1) - 1;
	pos2 = ft_strlen(n2) - 1;
	prev_result = 0;
	while (if_continue_add(n1, n2, pos1, pos2))
	{
		final_res--;
		ft_add(get_digit(n1, pos1), get_digit(n2, pos2), &prev_result, final_res);
		pos1--;
		pos2--;
	}
	remove_initial_zeros(&final_res);
	if (is_neg(n1) && is_neg(n2))
	{
		final_res--;
		*final_res = '-';
	}
	return (final_res);
}

char	*infin_sub(char *n1, char *n2)
{
	int		pos1;
	int		pos2;
	char 	*final_res;
	int		prev_result;

	final_res = malloc(sizeof(char) * (MAX_SIZE + 1));
	final_res += MAX_SIZE;
	(*final_res) = '\0';
	pos1 = ft_strlen(n1) - 1;
	pos2 = ft_strlen(n2) - 1;
	prev_result = 0;
	while (if_continue_add(n1, n2, pos1, pos2))
	{
		final_res--;
		ft_sub(get_digit(n1, pos1), get_digit(n2, pos2), &prev_result, final_res);
		pos1--;
		pos2--;
	}
	remove_initial_zeros(&final_res);
	if (is_neg(n2) && is_n2_biggest_nbr(n1, n2))
	{
		final_res--;
		*final_res = '-';
	}
	return (final_res);
}

void	select_op(char *n1, char *n2)
{
	if (!add_or_sub(n1, n2))
		ft_putstr(infin_add(n1, n2));
	else if (is_n2_biggest_nbr(n1, n2))
		ft_putstr(infin_sub(n1, n2));
	else
		ft_putstr(infin_sub(n2, n1));
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		select_op(argv[1], argv[2]);
	ft_putstr("\n");
	return (0);
}
