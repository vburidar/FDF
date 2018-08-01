/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:44:25 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 17:04:05 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	ft_nb_space(char *line)
{
	int	ret;

	ret = 0;
	while (*line)
	{
		if (*line == ' ')
			ret = ret + 1;
		line++;
	}
	return (ret);
}

int	ft_test_line(char *line)
{
	int	i;

	i = 0;
	if (*line == '\0')
		ft_exit(2);
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
			i = i + 1;
		line++;
	}
	if (i < 2)
		ft_exit(2);
	return (0);
}
