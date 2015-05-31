/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 10:07:20 by exam              #+#    #+#             */
/*   Updated: 2015/05/31 13:30:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Reasoning: create a string (result) that will hold the entire result
 * insert_digit: insert char or digit in string, depending on if it
 * is_digit or not
 * nbr_digits: returns the digits in a number
 * remove_extra_zeros: returns the result without 0s written before
 * the final value
 * is_ending: returns 1 once there are no more digits in n2 (2nd string)
 *
 * infin_mult: 
 * IDEA: get all the digits for a specific position in result
 * keeps calculating until all values from n1 OR n2 have been written
 * unit - holds the unit value that its  % 10 will be printed
 * dec - holds the decimal value that will become the unit value in
 * the next turn
 *
*/

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

void	ft_bzero(void *strptr, int size)
{
	unsigned char	*str;
	int				i;

	str = strptr;
	i = 0;
	while (i < size)
		str[i++] = '\0';
}

int		getdigit(char *str, int pos)
{
	if (pos < 0 || str[pos] == '-')
		return (0);
	return (str[pos] - '0');
}

void	insert_digit(char **result_ptr, int	c, t_bool is_digit)
{
	char *result;

	result = *result_ptr;
	result--;
	if (is_digit)
		*result = c + '0';
	else
		*result = c;
	*result_ptr = result;
}

int		ft_mult(int a, int b)
{
	return (a * b);
}

t_bool	isresultneg(char *n1, char *n2)
{
	return ((n1[0] == '-' && n2[0] != '-') || (n2[0] == '-' && n1[0] != '-'));
}

void	ft_putstr(char *str)
{
	write(1, str, (size_t)ft_strlen(str));
}

int		nbr_digits(char *str)
{
	int	nbr;

	nbr = ft_strlen(str);
	if (str[0] == '-')
		nbr--;
	return (nbr);
}

t_bool	is_ending(int end, char *n2)
{
	return (end < 0 || n2[end] == '-');
}

void	remove_extra_zeros(char **result_ptr)
{
	char *result;

	result = *result_ptr;
	while (*result == '0')
		result++;
	if (!result)
		result--;
	*result_ptr = result;
}

char	*infin_mult(char *n1, char *n2)
{
	char	*result;
	int		i1;
	int		i2;
	int		end;
	int		unit;
	int		dec;
	int		counter;

	result = malloc(sizeof(char) * (size_t)((ft_strlen(n1) + ft_strlen(n2) + 5)));
	ft_bzero(result, ft_strlen(n1) + ft_strlen(n2) + 5);
	result += ft_strlen(n1) + ft_strlen(n2) + 4;
	end = ft_strlen(n2) - 1;
	counter = 0;
	unit = 0;
	dec = 0;
	while (counter < nbr_digits(n1) || counter < nbr_digits(n2))
	{
		unit = dec;
		dec = 0;
		i1 = ft_strlen(n1) - 1 - counter;
		i2 = end + counter;
		while (i1 >= 0 && n1[i1] != '-' && n2[i2])
		{
			unit += ft_mult(getdigit(n1, i1), getdigit(n2, i2)) % 10;
			dec += ft_mult(getdigit(n1, i1), getdigit(n2, i2)) / 10;
			i2++;
			i1--;
		}
		end--;
		counter += is_ending(end, n2);
		insert_digit(&result, unit % 10, 1);
		dec += unit / 10;
	}
	while (dec != 0)
	{
		insert_digit(&result, dec % 10, 1);		
		dec /= 10;
	}
	remove_extra_zeros(&result);
	if (isresultneg(n1, n2))
		insert_digit(&result, '-', 0);
	return (result);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		if ((ft_strlen(argv[1]) == 1 && argv[1][0] == '0') ||
			(ft_strlen(argv[2]) == 1 && argv[2][0] == '0'))
			ft_putstr("0");
		else
			ft_putstr(infin_mult(argv[1], argv[2]));
	}
	ft_putstr("\n");
	return (0);
}
