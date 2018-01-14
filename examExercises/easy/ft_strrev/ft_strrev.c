/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:57:23 by tsilva            #+#    #+#             */
/*   Updated: 2015/05/05 20:22:28 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	i = 0;
	if (!str)
		return (str);
	len = ft_strlen(str);
	str[len--] = '\0';
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}
