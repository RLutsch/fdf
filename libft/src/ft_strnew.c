
#include <ft_fc_mem.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(*str));
	if (str == 0)
		return (0);
	ft_memset(str, 0, size + 1);
	return (str);
}
