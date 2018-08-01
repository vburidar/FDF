/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:52:52 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 17:13:29 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_coord	**ft_creation_array(int length, int width)
{
	int		i;
	t_coord	**ret;

	i = 0;
	if (!(ret = malloc((width) * sizeof(t_coord*))))
		ft_exit(1);
	while (i < width - 1)
	{
		if (!(ret[i] = malloc((length + 1) * sizeof(t_coord))))
			ft_exit(1);
		i = i + 1;
	}
	ret[i] = NULL;
	return (ret);
}

t_coord	**ft_allocate(int size, t_coord **tab_coord, int length)
{
	t_coord	**tmp;

	tmp = ft_creation_array(length, size);
	if (tab_coord != NULL)
	{
		tmp = ft_copy_tab(tab_coord, tmp);
		ft_free(tab_coord);
	}
	else
	{
		ft_free(tmp);
		tmp = NULL;
	}
	tab_coord = ft_creation_array(length, size);
	if (tmp != NULL)
	{
		tab_coord = ft_copy_tab(tmp, tab_coord);
		ft_free(tmp);
	}
	return (tab_coord);
}
