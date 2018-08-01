/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:09:54 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 16:28:20 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	ft_exit(int error)
{
	if (error == 1)
		ft_putstr("malloc a echoue\n");
	if (error == 2)
		ft_putstr("grille invalide\n");
	exit(1);
}
