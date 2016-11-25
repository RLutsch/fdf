/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:40:33 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 14:31:25 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//#include <mlx_int.h>
#include <mlx.h>
//#include <X.h>
#define KeyPressMask (1L<<1)
#define KeyReleaseMask (1L<<2)
#define	KeyPress 2
#define KeyRelease 3
#include <stdlib.h>
#include <fcntl.h>

static t_keys	*init_keys(void)
{
	t_keys		*keys;

	keys = (t_keys *)malloc(sizeof(t_keys));
	ft_assert(keys != NULL, "Cant malloc the keys.. Exiting...\n");
	keys->right = 0;
	keys->left = 0;
	keys->up = 0;
	keys->down = 0;
	keys->more_height = 0;
	keys->less_height = 0;
	keys->more_angle = 0;
	keys->less_angle = 0;
	keys->zoom = 0;
	keys->unzoom = 0;
	keys->rot_z = 0;
	return (keys);
}

static void		reset_init(t_mdata *mdata, float *scale, float *w, float *h)
{
	*scale = SCALE;
	*w = 0;
	*h = 0;
	mdata->angle = ANGLE;
	mdata->height = HEIGHT;
	mdata->shadows = 0;
}

void			reset_values(t_mdata *mdata)
{
	float		width;
	float		height;
	int			i;
	int			j;
	float		scale;

	reset_init(mdata, &scale, &width, &height);
	i = -1;
	while (mdata->map[++i])
	{
		++height;
		j = -1;
		while (mdata->map[i][++j] != -999)
			;
		width = (j > width ? j : width);
	}
	while (width * scale > mdata->w || height * scale > mdata->h)
		scale--;
	mdata->scale_x = scale;
	mdata->scale_y = scale;
	mdata->sx = width;
	mdata->sy = height;
	mdata->x = (mdata->w / 2) - (width * mdata->scale_x / 2);
	mdata->y = (mdata->h / 2) - (height * mdata->scale_x / 2);
}

int				**ft_init(char *map)
{
	int			fd;
	int			**matrix;

	if (0)
		ft_ext(map, ".fdf");
	fd = ft_open(map, O_RDWR);
	matrix = create_matrix(fd);
	ft_close(fd);
	fd = ft_open(map, O_RDONLY);
	matrix = fill_matrix(fd, matrix);
	return (matrix);
}

t_mdata			*init_mlx(int **map, int userwidth, int userheight)
{
	t_mdata		*mdata;

	mdata = (t_mdata *)malloc(sizeof(t_mdata));
	ft_assert(mdata != NULL, "Cant malloc the mdata... Exiting...\n");
	mdata->w = (userwidth > 0 ? userwidth : 900);
	mdata->h = (userheight > 0 ? userheight : mdata->w * 9 / 16);
	mdata->map = map;
	mdata->mptr = mlx_init();
	mdata->wptr = mlx_new_window(mdata->mptr, mdata->w, mdata->h, "FDF");
	mdata->iptr = NULL;
	mdata->keys = init_keys();
	mdata->debug = 0;
	mdata->shadows = 0;
	reset_values(mdata);
	mlx_do_key_autorepeatoff(mdata->mptr);
	mlx_hook(mdata->wptr, KeyPress, KeyPressMask, &key_press, mdata);
	mlx_hook(mdata->wptr, KeyRelease, KeyReleaseMask, &key_release, mdata);
	mlx_expose_hook(mdata->wptr, expose, mdata);
	mlx_loop_hook(mdata->mptr, loop, mdata);
	mlx_loop(mdata->mptr);
	return (mdata);
}
