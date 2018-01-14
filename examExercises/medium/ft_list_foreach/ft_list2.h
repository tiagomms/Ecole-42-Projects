/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 20:38:28 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 20:51:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIST2_H_
# define _FT_LIST2_H_

typedef struct    s_list
{
	struct s_list *next;
	int           data;
}                 t_list;

#endif
