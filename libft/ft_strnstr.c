/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 08:25:42 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/14 14:34:17 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (*haystack++)
	{
		while (x <= (int)len)
		{
			if (*haystack == needle[i])
				i++;
			if (i == (int)ft_strlen(needle))
				return ((char *)haystack - ft_strlen(needle));
			x++;
		}
		x = 0;
	}
	return (NULL);
}
