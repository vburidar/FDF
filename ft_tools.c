/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 16:04:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 11:04:40 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf.h"

int		ft_sens(int depart, int arrivee)
{
	if (arrivee > depart)
		return (1);
	else
		return (-1);
}

float	ft_div(float a, int b)
{
	return (a / b);
}

float	ft_rad(int angle)
{
	return (M_PI * ft_div(angle, 180));
}

int		ft_length(t_coord **tab_coord)
{
	int	i;

	i = 0;
	while (tab_coord[0][i].c)
		i = i + 1;
	return (i);
}

int		ft_width(t_coord **tab_coord)
{
	int	i;

	i = 0;
	while (tab_coord[i])
		i++;
	return (i);
}
