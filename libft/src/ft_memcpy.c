
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dstcpy;
	const char		*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	while (n--)
		*dstcpy++ = *srccpy++;
	return (dst);
}
