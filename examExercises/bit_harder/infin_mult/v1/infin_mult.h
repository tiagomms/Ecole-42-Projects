/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 18:26:10 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/12 19:58:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INFIN_MULT_H_
# define _INFIN_MULT_H_

# include <stdlib.h>
# include <unistd.h>

typedef int t_bool;
# define MAX_SIZE 20000

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	insert_digit(int digit, char *final_nbr);
char	*infin_add(char *n1, char *n2);
t_bool	is_neg(char *nbr);
int		get_digit(char *n, int pos);
void	ft_bcharzero(char *str, int size);
void	remove_initial_zeros(char **final_res_ptr);
void	infin_add_mod(char **current_total, int starting_total_pos, char *new_value);

#endif
