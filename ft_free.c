/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:54:53 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 17:00:27 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	ft_free(t_coord **tab_coord)
{
	int j;

	j = 0;
	while (tab_coord[j])
	{
		free(tab_coord[j]);
		j = j + 1;
	}
	free(tab_coord);
}
