/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:35:49 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/06 14:37:41 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

int	ft_rotz_x(t_coord **tab_coord, int angle, int i, int j)
{
	return (cos(ft_rad(angle)) * tab_coord[j][i].x
			- sin(ft_rad(angle)) * tab_coord[j][i].y);
}

int	ft_rotz_y(t_coord **tab_coord, int angle, int i, int j)
{
	return (sin(ft_rad(angle)) * tab_coord[j][i].x
			+ cos(ft_rad(angle)) * tab_coord[j][i].y);
}

int	ft_rotx_y(t_coord **tab_coord, int angle, int i, int j)
{
	return (cos(ft_rad(angle)) * tab_coord[j][i].y
			- sin(ft_rad(angle)) * tab_coord[j][i].z);
}

int	ft_rotx_z(t_coord **tab_coord, int angle, int i, int j)
{
	return (sin(ft_rad(angle)) * tab_coord[j][i].y
			+ cos(ft_rad(angle)) * tab_coord[j][i].z);
}
