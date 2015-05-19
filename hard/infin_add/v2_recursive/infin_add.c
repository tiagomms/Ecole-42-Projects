/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:22:39 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/19 19:57:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

typedef int t_bool;
# define MAX_SIZE 20000

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
	write(1, str, (size_t)ft_strlen(str));
}

t_bool	is_neg(char *n)
{
	return (n[0] == '-');
}

void	insert_digit(int digit, char **final_nbr_ptr)
{
	char *final_nbr;

	final_nbr = *final_nbr_ptr;
	final_nbr--;
	*final_nbr = digit + '0';
	*final_nbr_ptr = final_nbr;
}

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

t_bool	is_add_the_op(char *n1, char *n2)
{
	return (((!is_neg(n1) && !is_neg(n2)) || (is_neg(n1) && is_neg(n2))));
}

int		get_digit(char *n, int pos)
{
	if (pos < 0 || n[pos] == '-')
		return (0);
	return (n[pos] - '0');
}

t_bool	is_n2_bigger_nbr(char *n1, char *n2)
{
	size_t	len_n1;
	size_t	len_n2;
	size_t	i1;
	size_t	i2;

	len_n1 = ft_strlen(n1) - is_neg(n1);
	len_n2 = ft_strlen(n2) - is_neg(n2);
	if (len_n1 == len_n2)
	{
		i1 = is_neg(n1);
		i2 = is_neg(n2);
		while (n1[i1] == n2[i2])
		{
			i1++;
			i2++;
		}
		return (n2[i2] > n1[i1]);
	}
	return (len_n2 > len_n1);
}

char	*remove_extra_zeros(char *result)
{
	if (!(*result))
		return (--result);
	if (*result == '0')
		return (remove_extra_zeros(++result));
	return (result);
}

char	*infin_op(char *result, char *n1, char *n2, int (*f)(int, int), int pos1, int pos2, int prev_rest)
{
	int				op_result;
	
	if ((pos1 < 0 || n1[pos1] == '-') && (pos2 < 0 || n2[pos2] == '-'))
	{
		if (prev_rest / 10 == 0)
		{
			result = remove_extra_zeros(result);	
			if (is_neg(n2) && (is_n2_bigger_nbr(n1, n2) || is_neg(n1)))
			{
				result--;
				*result = '-';
			}
			return (result);
		}
		else
		{
			prev_rest /= 10;
			insert_digit(prev_rest, &result);
			return (infin_op(result, n1, n2, f, pos1, pos2, prev_rest));
		}
	}
	op_result = (*f)(get_digit(n2, pos2), get_digit(n1, pos1) + (prev_rest / 10));
	prev_rest = 0;
	if (op_result >= 10 || op_result < 0)
		prev_rest = 10;
	if (op_result < 0)
		op_result += 10;
	pos1--;
	pos2--;
	insert_digit(op_result % 10, &result);
	return (infin_op(result, n1, n2, f, pos1, pos2, prev_rest));
}

void	ft_bzero(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		str[i++] = '\0';
}

void	select_op(char *n1, char *n2)
{
	char	*result;

	result = malloc(sizeof(char) * MAX_SIZE + 1);
	ft_bzero(result, MAX_SIZE + 1);
	result += MAX_SIZE;
	if (is_add_the_op(n1, n2))
		ft_putstr(infin_op(result, n1, n2, ft_add, ft_strlen(n1) - 1, ft_strlen(n2) - 1, 0));
	else if (is_n2_bigger_nbr(n1, n2))
		ft_putstr(infin_op(result, n1, n2, ft_sub, ft_strlen(n1) - 1, ft_strlen(n2) - 1, 0));
	else
		ft_putstr(infin_op(result, n2, n1, ft_sub, ft_strlen(n2) - 1, ft_strlen(n1) - 1, 0));
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		select_op(argv[1], argv[2]);
	ft_putstr("\n");
	return (0);
}
