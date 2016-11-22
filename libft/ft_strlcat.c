/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:36:24 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/13 11:01:25 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	register char		*d;
	register const char	*s;
	register size_t		n;
	size_t				len;

	d = dst;
	s = src;
	n = size;
	while (*d++ != '\0' && n-- != 0)
		;
	len = d - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(s));
	while (*s++ != '\0')
	{
		if (n-- != 1)
		{
			*d++ = *s;
		}
	}
	*d = '\0';
	return (len + (s - src));
}
