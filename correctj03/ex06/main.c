/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 15:04:34 by tsilva            #+#    #+#             */
/*   Updated: 2014/09/01 16:23:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a,int *b);

int		main()
{	
	int p_a;
	int p_b;
	int *a;
	int *b;

	p_a = 1;
	p_b = 5;
	a = &p_a;
	b = &p_b;
	fprintf(stdout, "a= %d  b= %d\n", *a, *b);
	ft_swap(a,b);
	fprintf(stdout, "a= %d  b= %d\n", *a, *b);
	return (0);
}

	
