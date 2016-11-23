
#include <string.h>

void	*ft_memset(void *str, int character, size_t n)
{
	char			*str2;
	unsigned char	character2;

	str2 = (char *)str;
	character2 = (unsigned char)character;
	while (n--)
		*str2++ = character2;
	return (str);
}
