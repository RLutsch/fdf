/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:20:42 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/14 12:17:55 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1,
		const void *s2, size_t n)
{
	unsigned char *st1;
	unsigned char *st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n-- && st1++ && st2++)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
	}
	return (0);
}
