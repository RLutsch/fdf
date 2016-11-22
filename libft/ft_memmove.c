/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:14:22 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/13 09:27:58 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (len--)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
