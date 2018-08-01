/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:27 by vburidar          #+#    #+#             */
/*   Updated: 2017/11/30 19:05:14 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char*)(malloc((len + 1) * sizeof(char)))))
		return (NULL);
	else
	{
		while (i < len)
		{
			new[i] = s[i + start];
			i = i + 1;
		}
		new[i] = '\0';
		return (new);
	}
}
