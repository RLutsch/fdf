/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:39:48 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:39:50 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		count_line(int *line)
{
	int			i;

	i = 0;
	while (line[i] != -999)
		++i;
	return (i);
}

static void		draw_map_x(t_mdata *mdata, int x, int y)
{
	t_vertex	v1;
	t_vertex	v2;

	v1.x = (x * mdata->scale_x) + mdata->x;
	v1.y = (y * mdata->scale_y) + mdata->y;
	v2.x = ((x + 1) * mdata->scale_x) + mdata->x;
	v2.y = (y * mdata->scale_y) + mdata->y;
	v1.x += y * mdata->angle;
	v1.y -= mdata->map[y][x] * mdata->height;
	v2.x += y * mdata->angle;
	v2.y -= mdata->map[y][x + 1] * mdata->height;
	v1.color = (0 << 16) + (200 << 8) + 0;
	v1.color += ((int)(mdata->map[y][x] * mdata->height * 3) << 16) % 255;
	v1.color += ((int)(mdata->map[y][x] * mdata->height * 3) << 8) % 255;
	v1.color += (int)(mdata->map[y][x] * mdata->height * 3) % 255;
	v2.color = v1.color;
	draw_line(v1, v2, mdata);
}

static void		draw_map_y(t_mdata *mdata, int x, int y)
{
	t_vertex	v1;
	t_vertex	v2;

	v1.x = (x * mdata->scale_x) + mdata->x;
	v1.y = (y * mdata->scale_y) + mdata->y;
	v2.x = (x * mdata->scale_x) + mdata->x;
	v2.y = ((y + 1) * mdata->scale_y) + mdata->y;
	v1.x += y * mdata->angle;
	v1.y -= mdata->map[y][x] * mdata->height;
	v2.x += (y + 1) * mdata->angle;
	v2.y -= mdata->map[y + 1][x] * mdata->height;
	v1.color = (0 << 16) + (200 << 8) + 0;
	v1.color += ((int)(mdata->map[y][x] * mdata->height * 3) << 16) % 255;
	v1.color += ((int)(mdata->map[y][x] * mdata->height * 3) << 8) % 255;
	v1.color += (int)(mdata->map[y][x] * mdata->height * 3) % 255;
	v2.color = v1.color;
	draw_line(v1, v2, mdata);
}

void			draw_map(t_mdata *mdata)
{
	int		x;
	int		y;

	y = -1;
	while (mdata->map[++y])
	{
		x = -1;
		while (mdata->map[y][++x] != -999)
		{
			if (mdata->map[y][x + 1] != -999)
				draw_map_x(mdata, x, y);
			if (mdata->map[y + 1] && x < count_line(mdata->map[y + 1]))
				draw_map_y(mdata, x, y);
		}
	}
}
