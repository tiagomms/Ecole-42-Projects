/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gluearraywstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 21:42:10 by tsilva            #+#    #+#             */
/*   Updated: 2015/02/04 21:42:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char *ft_gluearraywstr(char **array, char *gluer)
{
	size_t	line;
	char	*glue_str;

	if (!array || !gluer)
		return (NULL);
	line = 0;
	while (array[line])
		glue_str = ft_strjoin(array[line++], gluer);
	return (glue_str);
}