/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:44:22 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/06 18:27:08 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)
						+ 1) * sizeof(char))))
		return (NULL);
	else
	{
		new = ft_strcpy(new, (char*)s1);
		new = ft_strcat((char*)new, (char*)s2);
		return (new);
	}
}
