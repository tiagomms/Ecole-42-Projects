/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 14:48:33 by tsilva            #+#    #+#             */
/*   Updated: 2014/09/01 15:00:28 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);

int		main()
{
	char *str;
	
	str = "Siga pa bingo";
	fprintf(stdout, "%s\n", str);
	fprintf(stdout, "%d\n", ft_strlen(str));
	return (0);
}
