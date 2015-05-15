/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 20:14:52 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 20:22:24 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str);


#include <stdio.h>

int		main()
{
	char str0[1000] = "";
	char str1[1000] = "abcde";
	char str2[1000] = "abcdef";
	char str3[1000] = "How are you doing";
	char str4[1000] = "Let's see what happens here with this example.<><";

	printf("str0\t|%s|\n", str0);
	printf("revstr0\t|%s|\n\n", ft_strrev(str0));
	printf("str1\t|%s|\n", str1);
	printf("revstr1\t|%s|\n\n", ft_strrev(str1));
	printf("str2\t|%s|\n", str2);
	printf("revstr2\t|%s|\n\n", ft_strrev(str2));
	printf("str3\t|%s|\n", str3);
	printf("revstr3\t|%s|\n\n", ft_strrev(str3));
	printf("str4\t|%s|\n", str4);
	printf("revstr4\t|%s|\n\n", ft_strrev(str4));
}
