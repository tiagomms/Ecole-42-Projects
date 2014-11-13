/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 11:40:38 by tsilva            #+#    #+#             */
/*   Updated: 2014/09/10 12:25:02 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LIST_H__
# define __FT_LIST_H__

# include <stdlib.h>

typedef struct s_list t_list;
struct s_list
{
	void	*tuff
	t_list	*next;
}

t_list	*ft_create_elem(void *data);

#endif
