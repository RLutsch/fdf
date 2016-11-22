/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 08:32:22 by rlutsch           #+#    #+#             */
/*   Updated: 2016/06/06 16:35:13 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*void	f4(int k, int *v, void *par)
{
	static int	*n;
	int			x;

	if (k != -1)
		mlx_clear_window(0, par);
	if ((x = -1) && k == -1)
		n = v;
	while (k == 0 && (++x <= n[4]))
	{
		obj_[x].a = obj_[x].a - 5;
		ft_dot(20, x, par, 0);
	}
	while (k == 2 && (++x <= n[4]))
	{
		obj_[x].a = obj_[x].a + 5;
		ft_dot(20, x, par, 0);
	}
	while (k == 123 && (++x <= n[4]))
	{
		obj_[x].hzx -= 0.1;
		ft_dot(20, x, par, 0);
	}
	while (k == 124 && (++x <= n[4]))
	{
		obj_[x].hzx += 0.1;
		ft_dot(20, x, par, 0);
	}
	while (k == 126 && (++x <= n[4]))
	{
		obj_[x].vzy -= 0.1;
		ft_dot(20, x, par, 0);
	}
	while (k == 125 && (++x <= n[4]))
	{
		obj_[x].vzy += 0.1;
		ft_dot(20, x, par, 0);
	}
}

*/

void	ft_display(t_boss obj)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while(y < (obj.maxy - 1))
	{
		++y;
		while(x < (obj.maxx -1))
		{
			draw_line(obj,x ,y);
			++x;
		}
		x = 0;
	}
}
/*

void     ft_dot(int s, int p, void *win, void *mlx)
{
	float   r;
	static float   x1;
	static float   y1;
	static float	x2;
	static float	y2;

	r = sqrt(obj_[p].x * obj_[p].x + obj_[p].y * obj_[p].y);
	
	x1 = r * cos(obj_[p].a * M_PI / 180) * s * obj_[p].hzx;// + j
	y1 = (r * sin(obj_[p].a * M_PI / 180)  + obj_[p].z) * s * obj_[p].vzy;// + k
	
	x2 = r * sin(obj_[p].a * M_PI / 180) * s * obj_[p].hzx;
	y2 = (r * cos(obj_[p].a * M_PI / 180) + obj_[p].z) * s * obj_[p].vzy;
	ft_putstr("X1 :");
	ft_putnbr(x1);
	ft_putstr( " Y1 :");
	ft_putnbr(y1);
	ft_putstr(" X2 :");
	ft_putnbr(x2);
	ft_putstr(" Y2 :");
	ft_putnbr(y2);
	ft_putstr("\n");	
	if (obj_[p].z != 0)
	{
		mlx_pixel_put(0, win, X / 2 + x1, Y / 2 + y1, 0x48ffa4);//to add colour
		draw_line(win, (X / 2 + x1),(Y / 2 + y1), (X / 2 + x2), (Y / 2 + y2));
	x1 = r * tan(obj_[p].a * M_PI / 180) * s * obj_[p].hzx;// + j
	y1 = (r * cos(obj_[p].a * M_PI / 180)  + obj_[p].z) * s * obj_[p].vzy;
 		x2 = r * tan(obj_[p].a * M_PI / 180) * s * obj_[p].hzx;
		y2 = (r * sin(obj_[p].a * M_PI / 180) + obj_[p].z) * s * obj_[p].vzy;

		draw_line(win, (X / 2 + x1),(Y /2 + y1), (X / 2 + x2), (Y / 2 + y2));



//		draw_line(win, (Y / 2 + y2), (X / 2 + x2), (Y / 2 + y1), (X / 2 + x1));
//		x2 = x1;
//		y2 = y1;
//	}
//	else
//	{
//		mlx_pixel_put(0, win, X / 2 + x1, Y / 2 + y1, 0x6e6e6e);
//		draw_line(win, (X / 2 + x1), (Y / 2 + y1), (X / 2 + x2), (Y / 2 + y2));
//		draw_line(win, (X / 2 + x2), (Y / 2 + y2), (X / 2 + x1), (Y / 2 + y1));
//		x2 = x1;
//		y2 = y1;
//	}
}

void	ft_calcpos(int *v, void *win, void *mlx)
{    
	float	r;
	int		p;
	float	s;

	s = 10;
	obj_[++v[4]].x = v[2] + 1;
	obj_[v[4]].y = v[1] + 1;
	obj_[v[4]].z = v[0];
	obj_[v[4]].hzx = 1.0; //vertical rotation 
	obj_[v[4]].vzy = 1.0; //horizontal rotation 
	obj_[v[4]].a = (atan(obj_[v[4]].y / obj_[v[4]].x)  * (180 / M_PI)) + 45;//init angle
}
*/
void	draw_line(t_boss obj, int x, int y)
{	
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	tx;
	float	ty;
	float	slope;

	x1 = obj.pts[y][x].x * obj.scale;
	if (x < obj.maxx)	
		x2 = obj.pts[y][x + 1].x * obj.scale;
	else x2 = x1;
	y1 = obj.pts[y][x].y * obj.scale;
	if (y < obj.maxy)
		y2 = obj.pts[y + 1][x].y * obj.scale;	
 	else y2 = y1;
	if (x2 < x1)
 	    swap_int(&x1, &x2, &y1, &y2);
   	slope = (y2 - y1)/(x2 - x1);
   	tx = x1;
    ty = y1;
	ft_putstr("\n X : ");
	ft_putnbr(x2);
	ft_putstr(" Y : ");
	ft_putnbr(y2);
    while (tx < x2)
    {
		mlx_pixel_put(0, obj.win, (X / 2)+ tx, (Y / 2) +ty, 0x00FFFF);
		tx++;
		ty += slope;
    }
   	if (y2 < y1)
		swap_int(&x1 ,&x2 ,&y1 ,&y2);
    tx = x1;
    ty = y1;
    slope = ((x2 - x1)/(y2 - y1));
    ft_putstr(" Here we are now : \n");
	while(ty < y2)
    	{
    		mlx_pixel_put(0, obj.win, (X / 2) + tx, (Y / 2) + ty, 0x00FFFF);
        	ty++;
        	tx += slope;
    	}
	ft_putstr("still here : \n");
}

void	swap_int(float *x1, float *x2, float *y1, float *y2)
{
    float *tx;
    float *ty;
    
    tx = x1;
    ty = y1;
    x1 = x2;
    y1 = y2;
    x2 = tx;
    y2 = ty;
}
/*
void draw_line(t_boss obj, int x, int y)
{
	float	slopeangle;
	float	r;
	float	x;
	float	y;

	slopeangle = atan((x2 - x1) / (y2 - y1) * (180 / M_PI));
	while (++r <= obj.scale)
	{
		x = r * cos((slopeangle) * M_PI / 180) + x1;
		y = r * sin((slopeangle) * M_PI / 180) + y1;
		mlx_pixel_put(0, win, X / 2 + x, Y / 2 + y, 0xFF00FF);
	}
	mlx_pixel_put(0, win, X / 2 + n1[0], Y / 2 + n1[1], 0x00FFFFFF);
}*/
