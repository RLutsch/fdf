
#include <ft_fc_dlist.h>
#include <stdlib.h>

t_dlist			*ft_addlastdlist(t_index *list, char *data)
{
	t_dlist		*node;

	if (list == NULL || data == NULL)
		return (NULL);
	node = (t_dlist *)malloc(sizeof(*node));
	if (node)
	{
		node->name = data;
		node->next = NULL;
		if (list->last == NULL)
		{
			list->first = node;
			list->last = node;
			node->prev = NULL;
		}
		else
		{
			list->last->next = node;
			node->prev = list->last;
			list->last = node;
		}
		list->size++;
	}
	return (node);
}
