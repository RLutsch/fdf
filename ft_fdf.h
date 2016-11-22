/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 08:13:35 by rlutsch           #+#    #+#             */
/*   Updated: 2016/06/23 10:49:23 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X 1000
# define Y 1000
# include "mlx.h"
# include <math.h>
# include "./libft/libft.h"

typedef struct
{
	float	x;
	float	y;
	float	z;
	char	c;
}			t_obj;

typedef struct
{
	t_obj	**pts;
	float	xrot;
	float	yrot;
	float	zrot;
	float	scale;
	float	elevation;
	void	*win;
	void	*mlx;
	float	maxx;
	float	maxy;
}			t_boss;

void    draw_line(t_boss obj, int x, int y);
void	ft_calcpos(int *v, void *win, void *mlx);
void	ft_dot(int s, int p, void *win, void *mlx);
void	f4(int k, int *v, void *par);
void    swap_int(float *x1, float *x2, float *y1, float *y2);
void    ft_display(t_boss obj);
#endif
