/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:33:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 16:09:39 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float	ft_size_square(t_coord *end)
{
	if (1080 * (end[1].x + end[0].x) / 1920 > end[1].y + end[0].y)
		return (ft_div(1920, (end[1].x + end[0].x)));
	else
		return (ft_div(1080, (end[1].y + end[0].y)));
}

void	ft_draw_tab(void *win, void *mlx, t_coord **tab_coord, t_coord angle)
{
	t_coord	len;
	t_coord *end;
	float	coeff;

	len.x = ft_length(tab_coord);
	len.y = ft_width(tab_coord);
	end = ft_set_end(tab_coord, len, angle);
	coeff = ft_size_square(end);
	tab_coord = ft_turn(tab_coord, angle, end, coeff);
	free(end);
	ft_print_image(tab_coord, mlx, win);
}
