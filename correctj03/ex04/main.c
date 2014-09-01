/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 14:22:58 by tsilva            #+#    #+#             */
/*   Updated: 2014/09/01 14:44:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);

int		main()
{
	char *tab;
	char *str;

	tab = "Olha me so este";
	str = &tab[0];
	fprintf(stdout, "%d\n", *str);
	ft_putstr(str);
	return (0);
}
