
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size - 1)
	{
		while (i < size - 1 && *src)
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = 0;
	}
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
