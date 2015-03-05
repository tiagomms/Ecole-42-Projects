/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:56:03 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/19 17:00:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	undo_last_operation(int current_tracker, int *a, int *b,
							t_format *format)
{
	if (current_tracker == 1)
		ft_swap(&a[0], &a[1]);
	else if (current_tracker == 2)
		ft_push(a, b, &format->size_a, &format->size_b);
	else if (current_tracker == 3)
		reverse_rotate(a, format->size_a);
	else if (current_tracker == 4)
		rotate(a, format->size_a);
	else if (current_tracker == 5)
		ft_swap(&b[0], &b[1]);
	else if (current_tracker == 6)
		ss(a, b, format);
	else if (current_tracker == 7)
		ft_push(b, a, &format->size_b, &format->size_a);
	else if (current_tracker == 8)
		reverse_rotate(b, format->size_b);
	else if (current_tracker == 9)
		rrr(a, b, format);
	else if (current_tracker == 10)
		rotate(b, format->size_b);
	else if (current_tracker == 11)
		rr(a, b, format);
}

t_bool	check_stop(int *undo, int ops_made, int last_op, int i)
{
	int		stop_op;

	if (!ops_made)
		return (1);
	if (last_op == 1 || last_op == 5 || last_op == 6)
		stop_op = last_op;
	else if (last_op == 2)
		stop_op = 7;
	else if (last_op == 3)
		stop_op = 4;
	else if (last_op == 4)
		stop_op = 3;
	else if (last_op == 7)
		stop_op = 2;
	else if (last_op == 8)
		stop_op = 10;
	else if (last_op == 9)
		stop_op = 11;
	else if (last_op == 10)
		stop_op = 8;
	else if (last_op == 11)
		stop_op = 9;
	if (stop_op == i)
		*undo = 1;
	return (stop_op != i);
}

t_bool	handle_push_swap(int ops_made, int ops_possible,
	t_format *format, int *tracker)
{
	int			i;
	int			undo;

	undo = 0;
	if (ops_made == ops_possible)
		return (correct_order(format->a, format, tracker, ops_possible));
	i = 1;
	while (i < 12)
	{
		tracker[ops_made] = i;
		if (check_stop(&undo, ops_made, tracker[ops_made - 1], i))
			operations_loop(format, i, &undo);
		if (undo == 0)
		{
			handle_push_swap(ops_made + 1, ops_possible,
							format, tracker);
			undo_last_operation(tracker[ops_made], format->a,
								format->b, format);
		}
		tracker[ops_made] = 0;
		undo = 0;
		i++;
	}
	return (0);
}

void	run_recursive(int *a, int *b, t_format format)
{
	int		op;
	int		tracker[MAX_OPS];

	format.a = a;
	format.b = b;
	op = 1;
	while (op < 7)
	{
		if (handle_push_swap(0, op, &format, tracker))
			break ;
		op++;
	}
}

int		main(int argc, char **argv)
{
	int			original[argc - 1];
	int			a[argc - 1];
	int			b[argc - 1];
	t_format	format;
	int			i;

	format = FORMAT(argc - 1, 0, argc - 1, a, b);
	i = 0;
	while (i < argc - 1)
	{
		a[i] = 0;
		i++;
	}
	i = 0;
	while (++i < argc)
		original[i - 1] = custom_atoi(argv[i]);
	sort_convert_numbers(original, a, &format);
	if (correct_order_zero_ops(a, &format))
		return (1);
	if (argc < 20)
		run_recursive(a, b, format);
	alternative(a, b, &format);
	ft_putchar('\n');
	return (0);
}
