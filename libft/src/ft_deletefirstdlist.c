
#include <ft_fc_dlist.h>
#include <stdlib.h>

t_index			*ft_deletefirstdlist(t_index *list)
{
	t_dlist		*tmp;

	if (list == NULL || list->first == NULL)
		return (NULL);
	tmp = list->first;
	if (list->first != list->last)
	{
		tmp->next->prev = NULL;
		list->first = tmp->next;
	}
	else
	{
		list->first = NULL;
		list->last = NULL;
	}
	free(tmp);
	tmp = 0;
	list->size--;
	return (list);
}
