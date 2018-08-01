/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:12:51 by vburidar          #+#    #+#             */
/*   Updated: 2018/01/09 17:16:50 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <math.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

t_coord	ft_fillcell(t_coord *tab_coord, char *line, char **tmp, t_coord coord)
{
	*line = '\0';
	while ((**tmp < '0' || **tmp > '9') && *tmp < line)
		(*tmp)++;
	if (**tmp >= '0' && **tmp <= '9')
	{
		tab_coord[coord.x].z = 100 * ft_atoi(*tmp);
		tab_coord[coord.x].y = 100 * coord.y;
		tab_coord[coord.x].x = 100 * coord.x;
		tab_coord[coord.x].c = 1;
		coord.x = coord.x + 1;
		*tmp = line;
	}
	return (coord);
}

t_coord	*ft_filltab(t_coord *tab_coord, char *line, t_coord coord)
{
	char	*tmp;
	int		test;

	coord.x = 0;
	test = 0;
	tmp = line;
	while (test == 0)
	{
		if (*line == ' ' || *line == '\0')
		{
			if (*line == '\0')
				test = 1;
			coord = ft_fillcell(tab_coord, line, &tmp, coord);
		}
		if (test == 0)
		{
			line = line + 1;
		}
	}
	tab_coord[coord.x].c = 0;
	return (tab_coord);
}

t_coord	**ft_load_file(t_coord **tab_coord, char **argv)
{
	int		fd;
	char	*line;
	t_coord	coord;
	int		size;

	coord.y = 0;
	size = 2;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		ft_test_line(line);
		tab_coord = ft_allocate(size, tab_coord, ft_strlen(line));
		tab_coord[coord.y] = ft_filltab(tab_coord[coord.y], line, coord);
		coord.y = coord.y + 1;
		tab_coord[coord.y] = NULL;
		free(line);
		size = size + 1;
	}
	if (size == 2)
		ft_exit(2);
	free(line);
	close(fd);
	return (tab_coord);
}

int		ft_keyevent(int keyevent, t_graph *pack)
{
	pack->tab_coord = ft_copy_tab(pack->init, pack->tab_coord);
	if (keyevent == 53)
	{
		ft_free(pack->init);
		ft_free(pack->tab_coord);
		free(pack);
		exit(1);
	}
	if (keyevent == 123)
		pack->angle.x = pack->angle.x + 5;
	if (keyevent == 124)
		pack->angle.x = pack->angle.x - 5;
	if (keyevent == 125)
		pack->angle.y = pack->angle.y + 5;
	if (keyevent == 126)
		pack->angle.y = pack->angle.y - 5;
	ft_draw_tab(pack->win, pack->mlx, pack->tab_coord, pack->angle);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_coord	**tab_coord;
	t_graph	*pack;

	pack = NULL;
	if (argc != 2)
		exit(1);
	tab_coord = NULL;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "mlx_42");
	tab_coord = ft_load_file(tab_coord, argv);
	ft_check_tab(tab_coord);
	pack = ft_init_pack(pack, tab_coord, mlx, win);
	ft_draw_tab(win, mlx, tab_coord, pack->angle);
	mlx_key_hook(win, ft_keyevent, pack);
	mlx_loop(mlx);
	ft_free(tab_coord);
	ft_free(pack->init);
	return (0);
}
