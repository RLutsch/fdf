
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1cpy;
	const unsigned char		*s2cpy;

	s1cpy = (const unsigned char *)s1;
	s2cpy = (const unsigned char *)s2;
	while (n--)
	{
		if (*s1cpy != *s2cpy)
			return (*s1cpy - *s2cpy);
		s1cpy++;
		s2cpy++;
	}
	return (0);
}
