/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 11:46:12 by exam              #+#    #+#             */
/*   Updated: 2015/05/19 16:59:26 by tsilva           ###   ########.fr       */
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

void	ft_bintzero(char *str, int size)
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

int		getdigit(char *str, int pos)
{
	if (pos < 0 || str[pos] == '-')
		return (0);
	return (str[pos] - '0');
}

void	ft_add(int a, int b, int *prev_result, char *added_nbr)
{
	int result;

	result = 0;
	if ((*prev_result) / 10 != 0)
		result += (*prev_result) / 10;
	result += a + b;
	*added_nbr = ((result % 10) + '0');
	*prev_result = result;
}

void	ft_mult(int a, int b, int *prev_result, char *mult_nbr)
{
	int result;

	result = 0;
	if ((*prev_result) / 10 != 0)
		result += (*prev_result) / 10;
	result += a * b;
	*mult_nbr = (result % 10) + '0';
	*prev_result = result;
}

int		is_result_neg(char *n1, char *n2)
{
	return (((n1[0] == '-' && n2[0] != '-') ||
			 (n2[0] == '-' && n1[0] != '-')));
}

void	remove_initial_zeros(char **strptr)
{
	char *str;

	str = *strptr;
	while (*str == '0')
		str++;
	*strptr = str;
}

void	get_rest_of_new_value(char **new_value_ptr, int prev_result)
{
	char *new_value;

	new_value = *new_value_ptr;
	if (prev_result / 10 != 0)
	{
		new_value--;
		*new_value = prev_result / 10 + '0';
		prev_result /= 10;
	}
	*new_value_ptr = new_value;
}

void	add_new_value_to_result(char *new_value, char **result_ptr, int pos2)
{
	char	*result;
	int		limit;
	int		prev_result;

	result = *result_ptr;
	result += MAX_SIZE - pos2;
	limit = ft_strlen(new_value);
	new_value += ft_strlen(new_value);
	prev_result = 0;
	while (*result != '0' || *new_value != '0' || limit > 0)
	{
		new_value--;
		result--;
		ft_add(*new_value - '0', *result - '0', &prev_result, result);
		limit--;
	}
}

char 	*infin_mult(char *n1, char *n2)
{
	char	new_value_static[MAX_SIZE - 1];
	char	*new_value;
	char	*result;
	int		pos1;
	int		pos2;
	int		prev_result;

	result = malloc(sizeof(char) * MAX_SIZE + 1);
	ft_bintzero(result, MAX_SIZE);
	pos2 = ft_strlen(n2) - 1;
	while (pos2 >= 0 && n2[pos2] != '-')
	{
		pos1 = ft_strlen(n1) - 1;
		ft_bintzero(new_value_static, MAX_SIZE - 2);
		new_value = (char*)new_value_static;
		new_value += MAX_SIZE - 2;
		prev_result = 0;
		while (pos1 >= 0 && n1[pos1] != '-')
		{
			new_value--;
			ft_mult(getdigit(n1, pos1), getdigit(n2, pos2), &prev_result, new_value);
			pos1--;
		}
		get_rest_of_new_value(&new_value, prev_result);
		add_new_value_to_result(new_value, &result, ft_strlen(n2) - 1 - pos2);
		pos2--;
	}
	remove_initial_zeros(&result);
	if (is_result_neg(n1, n2))
	{
		result--;
		*result = '-';
	}
	return (result);
}

int		main(int argc, char **argv)
{
	char *calc;
	if (argc == 3)
	{
		if ((ft_strlen(argv[1]) == 1 && argv[1][0] == '0') || (ft_strlen(argv[2]) == 1 && argv[2][0] == '0')) 
			write(1, "0", 1);
		else
		{
			calc = infin_mult(argv[1], argv[2]);
			write(1, calc, ft_strlen(calc));
		}
	}
	write(1, "\n", 1);
	return (0);
}
