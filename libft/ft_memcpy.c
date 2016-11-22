/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:17:50 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/13 09:19:17 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}
