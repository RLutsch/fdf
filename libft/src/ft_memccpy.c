
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)s1;
	srccpy = (const char *)s2;
	while (n--)
	{
		*dstcpy++ = *srccpy++;
		if (*(srccpy - 1) == (unsigned char)c)
			return ((void *)dstcpy);
	}
	return (0);
}
