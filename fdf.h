/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:40:53 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 16:26:27 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"

/*
**STRUCTURE FOR COORDINATES IN 3D
*/
typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
	char		c;
}				t_coord;

/*
**STRUCTURE FOR KEYEVENT
*/
typedef struct	s_graph
{
	void		*mlx;
	void		*win;
	t_coord		**tab_coord;
	t_coord		**init;
	t_coord		angle;
}				t_graph;

/*
**USEFUL TOOLS AND MATHEMATIC FONCTIONS
*/
float			ft_div(float a, int b);
float			ft_rad(int amgle);
int				ft_length(t_coord **tab_coord);
int				ft_width(t_coord **tab_coord);
int				ft_sens(int depart, int arrivee);
void			ft_exit(int error);

/*
**POINT OF VIEW MANAGMENT
*/
void			ft_draw_tab(void *win, void *mlx, t_coord **tab, t_coord angle);
t_coord			**ft_turn(t_coord **tab, t_coord ang, t_coord *vec, float coef);
t_coord			*ft_set_end(t_coord **tab_coord, t_coord len, t_coord angle);
int				ft_rotz_x(t_coord **tab_coord, int angle, int i, int j);
int				ft_rotz_y(t_coord **tab_coord, int angle, int i, int j);
int				ft_rotx_y(t_coord **tab_coord, int angle, int i, int j);
int				ft_rotx_z(t_coord **tab_coord, int angle, int i, int j);

/*
**IMAGE CREATION AND PRINTING
*/
void			ft_print_image(t_coord **tab_coord, void *mlx, void *window);
t_coord			ft_init_color(void);

/*
**ALLOCATION AND FREEING OF COORDINATES' ARRAY
*/
t_graph			*ft_init_pack(t_graph *p, t_coord **tab, void *mlx, void *win);
t_coord			**ft_allocate(int size, t_coord **tab_coord, int length);
t_coord			**ft_copy_tab(t_coord **input, t_coord **output);
void			ft_free(t_coord **tab_coord);
int				ft_test_line(char *line);
void			ft_check_tab(t_coord **tab_coord);
#endif
