/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_errs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:51:00 by tsilva            #+#    #+#             */
/*   Updated: 2015/01/10 22:52:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_return_errs(int code, char *function_w_error)
{
	if (code == -1)
		perror("Open failed: ");
	else if (code == -2)
		perror("Read failed: ");
	else if (code == -3)
		perror("Close failed: ");
	else if (code == -4)
		perror("Invalid file: Please give a correct file\n");
	if (code == -1 || code == -2 || code == -3)
		strerror(errno);
	if (function_w_error != NULL)
		perror(ft_strjoin(function_w_error, "- Project failed"));
	return (code);
}
