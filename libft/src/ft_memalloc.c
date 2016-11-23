
#include <ft_fc_mem.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (0);
	ptr = malloc(size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
