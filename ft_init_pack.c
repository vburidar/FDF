/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:22:16 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 16:57:29 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_coord	**ft_copy_tab(t_coord **input, t_coord **output)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (input[j])
	{
		while (input[0][i].c)
		{
			output[j][i].x = input[j][i].x;
			output[j][i].y = input[j][i].y;
			output[j][i].z = input[j][i].z;
			output[j][i].c = input[j][i].c;
			i = i + 1;
		}
		output[j][i].c = 0;
		i = 0;
		j = j + 1;
	}
	return (output);
}

t_coord	**ft_alloc_tab(t_coord **tab_coord)
{
	int		i;
	int		j;
	t_coord	**new;

	i = 0;
	j = 0;
	while (tab_coord[j])
		j++;
	if (!(new = malloc((j + 1) * sizeof(t_coord*))))
		exit(1);
	while (tab_coord[0][i].c)
		i++;
	new[j] = NULL;
	j = 0;
	while (tab_coord[j])
	{
		if (!(new[j] = malloc((i + 1) * sizeof(t_coord))))
			exit(1);
		new[j][i].c = 0;
		j++;
	}
	return (new);
}

t_coord	**ft_tabdup(t_coord **tab_coord)
{
	t_coord	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_alloc_tab(tab_coord);
	while (tab_coord[j])
	{
		while (tab_coord[0][i].c)
		{
			new[j][i].x = tab_coord[j][i].x;
			new[j][i].y = tab_coord[j][i].y;
			new[j][i].z = tab_coord[j][i].z;
			new[j][i].c = tab_coord[j][i].c;
			i = i + 1;
		}
		new[j][i].c = 0;
		i = 0;
		j = j + 1;
	}
	return (new);
}

t_graph	*ft_init_pack(t_graph *pack, t_coord **tab_coord, void *mlx, void *win)
{
	if (!(pack = (t_graph*)malloc(sizeof(t_graph))))
		exit(1);
	pack->mlx = mlx;
	pack->win = win;
	pack->tab_coord = tab_coord;
	pack->init = ft_tabdup(tab_coord);
	pack->angle.x = 60;
	pack->angle.y = 45;
	pack->angle.z = 45;
	return (pack);
}
