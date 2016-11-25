/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:42:59 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:43:11 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_keys
{
	char			right;
	char			left;
	char			up;
	char			down;
	char			more_height;
	char			less_height;
	char			more_angle;
	char			less_angle;
	char			zoom;
	char			unzoom;
	char			rot_z;
}					t_keys;

typedef struct		s_mdata
{
	void			*mptr;
	void			*wptr;
	void			*iptr;
	char			*idata;
	t_keys			*keys;
	int				w;
	int				h;
	int				**map;
	float			scale_x;
	float			scale_y;
	float			angle;
	float			height;
	float			x;
	float			y;
	int				sx;
	int				sy;
	int				bpp;
	int				sizeline;
	int				endian;
	char			debug;
	char			shadows;
}					t_mdata;

typedef struct		s_vertex
{
	float			x;
	float			y;
	float			z;
	float			w;
	unsigned int	color;
}					t_vertex;

typedef struct		s_delta
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
}					t_delta;
#endif
