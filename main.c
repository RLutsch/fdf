/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 08:04:59 by rlutsch           #+#    #+#             */
/*   Updated: 2016/06/23 13:53:47 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		my_key(int	keycode, void *par)
{
	ft_putendl(ft_itoa(keycode));
	if(keycode == 53)
		exit (0);
/*	if (keycode == 0)//A  left rotation
		f4(keycode, 0, par);
	if (keycode == 2)//D  right rotation
		f4(keycode, 0, par);
	if (keycode == 123)//l
		f4(keycode, 0, par);
	if (keycode == 124)//r
		f4(keycode, 0, par);
	if (keycode == 126)//u
		f4(keycode, 0, par);
	if (keycode == 125)//d
		f4(keycode, 0, par);
	if (keycode == 8)
		mlx_clear_window(0, par);
*/
	return (0);
}


int		line_counter(char *filename)
{
	int	ctr;
	int	fd;
	char *l;

	ctr = 0;
	fd = open(filename, O_RDONLY);
	while(get_next_line(fd, &l) != 0)
			ctr++;
	close(fd);
	return (ctr);
	
}

int		space_counter(char *filename)
{
	int ctr;
	int fd;
	char *l;

	ctr = 0;
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &l);
	ctr = strcmp(l, " ");
	ctr = (ctr + 3);
	close(fd);
	return (ctr);
}

t_boss    ft_readfile(char *fn, char *l, t_boss obj)
{
	char    **av;
	int		x;
	int		y;
	int		cnt;
	int		fd;
	int		i;

	fd = open(fn, O_RDONLY);
	obj.maxy = line_counter(fn);
	obj.maxx = space_counter(fn);
	y = 0;
	x = 0;
	i = 0;
	obj.pts = (t_obj **)malloc(sizeof(t_obj *) * (obj.maxy + 1));
	while (get_next_line(fd, &l) != 0)
	{	
		av = ft_strsplit(l, ' ');
		obj.pts[y] = (t_obj *)malloc(sizeof(t_obj) * (obj.maxx + 2));
		while (av[i])
		{
			obj.pts[y][x].x = x;
			obj.pts[y][x].y = y;
			obj.pts[y][x].z = ft_atoi(av[x]);
			x++;
			i++;
		}
		x = 0;
		y++;
		i = 0;
	}
	close(fd);
	return (obj);
}

int     main(int ac, char **av)
{
	t_boss obj;
	int     fd;
	int     v[6];
	char    *l;

//	v[1] = -1;
//	v[4] = -1;
	obj.scale = 10;
	obj.yrot = 45;
	obj.xrot = 45;
	obj.zrot = 45;
	obj.mlx = mlx_init();
    obj.win = :wq
    mlx_new_window(obj.mlx, X, Y, "ft_fdf");
//	if (ac > 1 && (fd = open(av[1], O_RDONLY)))
	
	if (ac > 1) 
		obj = ft_readfile(av[1], l, obj);
	ft_putstr("display file\n");
	ft_display(obj);
	ft_putstr("\n reading object\n");
//	v[5] = 1;
//	f4(-1, v, 0);
	mlx_key_hook(obj.win, my_key, obj.win);
	mlx_loop(obj.mlx);
	return (0);
}
