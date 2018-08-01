/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:54:57 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 11:17:10 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fdf.h"

static t_coord	ft_search_max(t_coord coord,
		t_coord **tab_coord, t_coord angle, t_coord ret)
{
	t_coord	vec;

	vec.x = ft_rotz_x(tab_coord, angle.x, coord.x, coord.y);
	vec.y = ft_rotz_y(tab_coord, angle.x, coord.x, coord.y);
	vec.y = cos(ft_rad(angle.y)) * vec.y
		- sin(ft_rad(angle.y)) * tab_coord[coord.y][coord.x].z;
	if (vec.x > ret.x)
		ret.x = vec.x;
	if (vec.y > ret.y)
		ret.y = vec.y;
	return (ret);
}

static t_coord	ft_search_min(t_coord coord,
		t_coord **tab_coord, t_coord angle, t_coord ret)
{
	t_coord	vec;

	vec.x = ft_rotz_x(tab_coord, angle.x, coord.x, coord.y);
	vec.y = ft_rotz_y(tab_coord, angle.x, coord.x, coord.y);
	vec.y = cos(ft_rad(angle.y)) * vec.y
		- sin(ft_rad(angle.y)) * tab_coord[coord.y][coord.x].z;
	if (-vec.x > ret.x)
		ret.x = -vec.x;
	if (-vec.y > ret.y)
		ret.y = -vec.y;
	return (ret);
}

t_coord			*ft_set_end(t_coord **tab_coord, t_coord len, t_coord angle)
{
	t_coord	*ret;
	t_coord	coord;

	coord.x = 0;
	coord.y = 0;
	if (!(ret = malloc(2 * sizeof(t_coord))))
		exit(1);
	ret[0].x = 0;
	ret[0].y = 0;
	ret[1].x = 0;
	ret[1].y = 0;
	while (coord.y < len.y)
	{
		while (coord.x < len.x)
		{
			ret[0] = ft_search_min(coord, tab_coord, angle, ret[0]);
			ret[1] = ft_search_max(coord, tab_coord, angle, ret[1]);
			coord.x = coord.x + 1;
		}
		coord.x = 0;
		coord.y = coord.y + 1;
	}
	return (ret);
}
