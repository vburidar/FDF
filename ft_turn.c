/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 16:49:22 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 16:32:47 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fdf.h"

t_coord	**ft_turn(t_coord **tab_coord, t_coord angle, t_coord *vec, float cf)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	while (tab_coord[j])
	{
		while (tab_coord[0][i].c)
		{
			tmp = (ft_rotz_x(tab_coord, angle.x, i, j) + vec[0].x) * cf;
			tab_coord[j][i].y = ft_rotz_y(tab_coord, angle.x, i, j);
			tab_coord[j][i].x = tmp + 960 - ((vec[1].x + vec[0].x) * cf / 2);
			tmp = (ft_rotx_y(tab_coord, angle.y, i, j) + vec[0].y) * cf;
			tab_coord[j][i].y = tmp + 540 - ((vec[1].y + vec[0].y) * cf / 2);
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	return (tab_coord);
}
