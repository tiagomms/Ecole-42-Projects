/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 21:17:25 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/19 20:16:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alph.h"

size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		while(str[len])
			len++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	replace_spcs_for_nulls(char *str, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = '\0';
		i++;
	}
}

char	**set_initial_strptr(char *str, size_t len)
{
	size_t	i;
	size_t	word;
	char	**array_of_ptrs;

	i = 0;
	array_of_ptrs = malloc(sizeof(char*) * 10000);
	word = 0;
	while (i < len)
	{
		if (str[i] == '\0')
			i++;
		else
		{
			array_of_ptrs[word++] = &str[i];
			i += ft_strlen(&str[i]);
		}
	}
	array_of_ptrs[word] = NULL;
	return (array_of_ptrs);
}

void	ft_swap_ptrs(void **str1, void **str2)
{
	void *temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}


int		ft_strequ_mod(char *str1, char *str2)
{
	size_t i;
	
	if (ft_strlen(str1) < ft_strlen(str2))
		return (-1);
	if (ft_strlen(str2) < ft_strlen(str1))
		return (1);
	i = 0;
	while (str1[i])
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] >= 'A' && str1[i] <= 'Z' && str2[i] == str1[i] + 32)
			i++;
		else if (str1[i] >= 'a' && str1[i] <= 'z' && str2[i] == str1[i] - 32)
			i++;
		else
			break ;
	}
	return (str1[i] - str2[i]);
}


void	sort_array(char ***ptr_array_of_ptrs)
{
	int		changed;
	size_t	i;
	char **array_of_ptrs;

	changed = 1;
	array_of_ptrs = *ptr_array_of_ptrs;
	while (changed)
	{
		changed = 0;
		i = 0;
		while (array_of_ptrs[i + 1])
		{
			if (ft_strequ_mod(array_of_ptrs[i], array_of_ptrs[i + 1]) > 0)
			{
				ft_swap_ptrs((void**)&(array_of_ptrs[i]),
							 (void**)&(array_of_ptrs[i + 1]));
				changed = 1;
			}
			i++;
		}
	}
}

void	ord_alphlong(char *altered_str, size_t total_len)
{
	char	**array_of_ptrs;
	size_t	word;

	array_of_ptrs = set_initial_strptr(altered_str, total_len);
	if (!array_of_ptrs[0])
		return ;
	sort_array(&array_of_ptrs);
	word = 0;
	ft_putstr(array_of_ptrs[word++]);
	while (array_of_ptrs[word])
	{
		if (ft_strlen(array_of_ptrs[word - 1])
			== ft_strlen(array_of_ptrs[word]))
			ft_putstr(" ");
		else
			ft_putstr("\n");
		ft_putstr(array_of_ptrs[word]);
		word++;
	}
}

int		main(int argc, char **argv)
{
	size_t total_len;
	
	if (argc == 2)
	{
		total_len = ft_strlen(argv[1]);
		replace_spcs_for_nulls(argv[1], total_len);
		ord_alphlong(argv[1], total_len);
	}
	ft_putstr("\n");
}
