/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:03:20 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 16:12:33 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "fdf.h"

char	*ft_get_image(void *image)
{
	char	*str;
	int		*params;

	if (!(params = (int*)(malloc(3 * (sizeof(int))))))
		ft_exit(1);
	str = mlx_get_data_addr(image, params, params + 1, params + 2);
	free(params);
	return (str);
}

void	ft_color_pixel(char *str, t_coord coord, t_coord color)
{
	if (coord.y * 1920 * 4 + coord.x * 4 > 0
		&& (coord.y * 1920 * 4 + coord.x * 4 + 2) < 1920 * 1080 * 4)
	{
		str[coord.y * 1920 * 4 + coord.x * 4] = (char)(color.x);
		str[coord.y * 1920 * 4 + coord.x * 4 + 1] = (char)(color.y);
		str[coord.y * 1920 * 4 + coord.x * 4 + 2] = (char)(color.z);
	}
}

void	ft_segx(char *str, t_coord a, t_coord b)
{
	t_coord curseur;

	curseur.x = a.x;
	curseur.y = a.y;
	curseur.z = fmax(a.z, b.z);
	while (curseur.x != b.x || curseur.y != b.y)
	{
		curseur.x = curseur.x + ft_sens(a.x, b.x);
		while ((10000 * abs(curseur.y - a.y)) / abs(curseur.x - a.x)
				< (10000 * abs(b.y - a.y)) / abs(b.x - a.x))
			curseur.y = curseur.y + ft_sens(a.y, b.y);
		ft_color_pixel(str, curseur, ft_init_color());
	}
}

void	ft_seg_image(char *str, t_coord a, t_coord b)
{
	t_coord	curseur;

	curseur.x = a.x;
	curseur.y = a.y;
	if (abs(curseur.x - b.x) > abs(curseur.y - b.y))
	{
		ft_segx(str, a, b);
		ft_color_pixel(str, curseur, ft_init_color());
	}
	else
	{
		while (curseur.x != b.x || curseur.y != b.y)
		{
			curseur.y = curseur.y + ft_sens(a.y, b.y);
			while ((10000 * abs(curseur.x - a.x)) / abs(curseur.y - a.y)
					< (10000 * abs(b.x - a.x)) / abs(b.y - a.y))
				curseur.x = curseur.x + ft_sens(a.x, b.x);
			ft_color_pixel(str, curseur, ft_init_color());
		}
		ft_color_pixel(str, curseur, ft_init_color());
	}
}

void	ft_print_image(t_coord **tab_coord, void *mlx, void *window)
{
	void	*image;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	image = mlx_new_image(mlx, 1920, 1080);
	mlx_put_image_to_window(mlx, window, image, 0, 0);
	str = ft_get_image(image);
	while (tab_coord[j + 1])
	{
		while (tab_coord[j][i + 1].c)
		{
			ft_seg_image(str, tab_coord[j][i], tab_coord[j + 1][i]);
			ft_seg_image(str, tab_coord[j][i], tab_coord[j][i + 1]);
			ft_seg_image(str, tab_coord[j + 1][i], tab_coord[j + 1][i + 1]);
			i++;
		}
		ft_seg_image(str, tab_coord[j][i], tab_coord[j + 1][i]);
		j++;
		i = 0;
	}
	mlx_put_image_to_window(mlx, window, image, 0, 0);
	mlx_destroy_image(mlx, image);
}
