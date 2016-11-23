
#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index			*ft_createdlist(void)
{
	t_index		*tmp;

	tmp = (t_index *)malloc(sizeof(*tmp));
	if (tmp)
	{
		tmp->size = 0;
		tmp->first = NULL;
		tmp->last = NULL;
	}
	return (tmp);
}
