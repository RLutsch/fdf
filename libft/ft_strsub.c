/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:55:09 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/31 13:42:18 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	while (i < len)
		*(new_str) = *(s + start + (i++));
	return (new_str);
}
