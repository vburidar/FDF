/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:23:43 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 17:05:15 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_tab(t_coord **tab_coord)
{
	int j;
	int i;
	int length;

	j = 0;
	i = 0;
	while (tab_coord[0][i].c)
		i = i + 1;
	length = i;
	i = 0;
	while (tab_coord[j])
	{
		while (tab_coord[j][i].c)
			i++;
		if (i != length)
			ft_exit(2);
		i = 0;
		j = j + 1;
	}
}
