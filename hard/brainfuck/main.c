/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 17:39:22 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 19:46:29 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include <stdio.h>

/*
** When to use char **str_ptr, or char *str in bzero or other
** functions, in void functions
** bzero(void *str, int size): you don't want to affect the value of
** the str, only the values inside each address connected to it. 
** 
** strdel(char **str_ptr): Here you want to free(*str_ptr), and then
** set the value of string to NULL (*str_ptr = NULL).
** You have affected its value!
** str_ptr, after *str_ptr = NULL, will be a pointer to NULL.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_bzero(void *str_ptr, int size)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = str_ptr;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

void	go_back(char *code_str, int *start, int bit_value)
{
	int i;
	int n_parenthesis;

	i = *start;
	n_parenthesis = 1;
	if (bit_value != 0)
	{
		i--;
		while (i && n_parenthesis != 0)
		{
			if (code_str[i] == ']')
				n_parenthesis++;
			else if (code_str[i] == '[')
				n_parenthesis--;
			if (n_parenthesis != 0)
				i--;
		}
	}
	*start = i;
}

void	go_forward(char *code_str, int *start, int bit_value)
{
	int i;
	int n_parenthesis;

	i = *start;
	n_parenthesis = 1;
	if (bit_value == 0)
	{
		i++;
		while (code_str[i] && n_parenthesis != 0)
		{
			if (code_str[i] == '[')
				n_parenthesis++;
			else if (code_str[i] == ']')
				n_parenthesis--;
			if (n_parenthesis != 0)
				i++;
		}
	}
	*start = i;
}

void	interpreter(char *code_str, int *i, int *result_pos, char *result_str)
{
	char code_c;

	code_c = code_str[*i];
	if (code_c == '>')
		(*result_pos)++;
	else if (code_c == '<')
		(*result_pos)--;
	else if (code_c == '+')
		result_str[(*result_pos)] += 1;
	else if (code_c == '-')
		result_str[(*result_pos)] -= 1;
	else if (code_c == '.')
		ft_putchar(result_str[(*result_pos)]);
	else if (code_c == '[')
		go_forward(code_str, i, result_str[(*result_pos)]);
	else if (code_c == ']')
		go_back(code_str, i, result_str[(*result_pos)]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		pos;
	int		op;
	char	buf[BUF_SIZE];

	if (argc == 2)
	{
		i = 0;
		op = 0;
		pos = 0;
		ft_bzero((void*)buf, BUF_SIZE);
		while (argv[1][i] && op < MAX_OPS)
		{
			interpreter(argv[1], &i, &pos, (char*)buf);
			i++;
			op++;
		}
	}
	ft_putchar('\n');
}
