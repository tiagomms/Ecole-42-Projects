/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:26:48 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/24 18:22:14 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# define FORMAT(a,b,c,d,e)              ((t_format){(a), (b), (c), (d), (e)})
# define MAX_OPS 256

typedef char	t_bool;

typedef struct	s_format
{
	int			size_a;
	int			size_b;
	int			stack_size;
	int			*a;
	int			*b;
}				t_format;

void			rotate(int *array, int size);
void			rr(int *a, int *b, t_format *format);
void			reverse_rotate(int *array, int size);
void			rrr(int *a, int *b, t_format *format);
void			ft_swap(int *first, int *second);
void			ss(int *a, int *b, t_format *format);
void			ft_push(int *add_first, int *remove_first,
						int *size_add, int *size_remove);
t_bool			correct_order(int *a, t_format *format,
								int *tracker, int ops_possible);
void			sort_convert_numbers(int *original, int *a, t_format *format);
void			print_array(int *array, int length);
void			operations_loop(t_format *format,
								int i, int *undo);
void			turn_tracker_string(int *tracker, int size, int i);
t_bool			correct_order_zero_ops(int *a, t_format *format);
void			alternative(int *a, int *b, t_format *format);
int				custom_atoi(const char *str);

#endif
