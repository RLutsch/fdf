
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char		*strcopy;

	strcopy = (const unsigned char *)str;
	while (n--)
	{
		if (*strcopy == (unsigned char)c)
			return ((void *)strcopy);
		strcopy++;
	}
	return (0);
}
