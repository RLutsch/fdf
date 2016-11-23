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