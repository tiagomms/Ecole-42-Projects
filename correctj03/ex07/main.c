/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 17:18:44 by tsilva            #+#    #+#             */
/*   Updated: 2014/09/01 20:23:52 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrev(char *str);

int main(void)
{
    char *tab;
		
	tab = strdup("Allons a la plage");
	fprintf(stdout, "%s\n", tab);
    ft_strrev(tab);
	fprintf(stdout, "\n%s\n", tab);
    return (0);
}
