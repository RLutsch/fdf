/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 08:14:40 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/14 08:39:59 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	while (*haystack++)
	{
		if (*haystack == needle[i])
			i++;
		if (i == (int)ft_strlen(needle))
			return ((char *)haystack - ft_strlen(needle));
	}
	return (NULL);
}
