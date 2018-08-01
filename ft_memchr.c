/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:32:51 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/06 14:34:18 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memchr(const void *src, int c, size_t taille)
{
	size_t	i;
	char	*curseur;

	i = 0;
	curseur = (char*)(src);
	while (i < taille)
	{
		if (curseur[i] == (char)(c))
			return (curseur + i);
		i = i + 1;
	}
	return (NULL);
}
