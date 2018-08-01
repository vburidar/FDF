/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:16:52 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/06 14:41:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t taille)
{
	size_t	i;
	char	*curseur;
	char	*arrivee;

	curseur = (char*)(src);
	arrivee = (char*)(dest);
	if (dest > src)
	{
		i = taille;
		while (i != 0)
		{
			arrivee[i - 1] = curseur[i - 1];
			i = i - 1;
		}
	}
	else
	{
		i = 0;
		while (i < taille)
		{
			arrivee[i] = curseur[i];
			i = i + 1;
		}
	}
	return (dest);
}
