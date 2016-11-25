/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:58:46 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:58:48 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_list.h>
#include <ft_fc_mem.h>
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;
	void		*contentcpy;
	size_t		content_sizecpy;

	content_sizecpy = content_size;
	tmp = (t_list *)malloc(sizeof(*tmp));
	if (tmp)
	{
		if (content == 0)
		{
			content_sizecpy = 0;
			tmp->content = NULL;
		}
		else
		{
			contentcpy = malloc(content_sizecpy);
			ft_memcpy(contentcpy, content, content_sizecpy);
			tmp->content = contentcpy;
		}
		tmp->content_size = content_sizecpy;
		tmp->next = 0;
	}
	else
		return (0);
	return (tmp);
}
