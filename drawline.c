/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 11:32:21 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/31 08:31:42 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw_line(void **a, float x1, float y1, float x2, float y2);
void	swap_int(float *x1, float *x2, float *y1, float *y2);
void	draw_square(void **a, float x1, float y1, float x2, float y2);

int	main()
{
    void	*mlx;
	void	*win;
	void	*tmp[2];
	int		x[4];

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "mlx 42");
	tmp[0] = mlx;
	tmp[1] = win;
	x[0] = 5;
	x[1] = 400;
	x[2] = 300;
	x[3] = 300;
	draw_square(tmp, x[0], x[1], x[2], x[3]);
	mlx_loop(mlx);
	return (0);
}

void draw_square(void **a, float x1, float y1, float x2, float y2)
{
	float	dst;
		draw_line(a, x1, y1, x2, y2);	
		dst = sqrt(pow((x2 - x1),2)+pow((y2 - y1), 2));
//		x1 = x1 - dst;
//		x2 = x2 + dst;
		y1 = y1 + dst;
		y2 = y2 + dst;
		draw_line(a, x1, y1, x2, y2); 
}

void	draw_line(void **a, float x1, float y1, float x2, float y2)
{
	float	slope;
	float	x;
	float	y;
	
	if (x2 < x1)
		swap_int(&x1, &x2, &y1, &y2);	
	slope = ((y2 - y1)/(x2 - x1));
   	x = x1;
	y = y1;	
	while (x < x2)
	{
		mlx_pixel_put(a[0], a[1], x, y, 0x00FFFF); 
		x++;
		y += slope;
	}
	if (y2 < y1)
		swap_int(&x1,&x2,&y1,&y2);
	x = x1;
	y = y1;
	slope = ((x2 - x1)/(y2 - y1));
	while(y < y2)
	{
		mlx_pixel_put(a[0], a[1], x, y, 0x00FFFF);
		y++;
		x += slope;
	}
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

int     ft_abs(int nb)
{
    if (nb < 0)
        return (nb *= -1);
    return (nb);
}
