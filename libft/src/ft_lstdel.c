
#include <ft_fc_list.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (*alst != 0 && alst != 0 && del != 0)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = 0;
		ft_lstdel(&tmp, del);
	}
}
