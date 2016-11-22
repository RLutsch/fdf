/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:17:40 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/15 13:06:07 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *const dst, const void *src, int c, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == c)
			return ((char *)&(dst[i + 1]));
		i++;
	}
	return (NULL);
}
