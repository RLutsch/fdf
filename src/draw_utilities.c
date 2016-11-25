/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:39:57 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:39:59 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

t_vertex		to_vertex(float x, float y, float z, int color)
{
	t_vertex	v;

	v.x = (float)x;
	v.y = (float)y;
	v.z = (float)z;
	v.w = 1.0;
	v.color = color;
	return (v);
}
