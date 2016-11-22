/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 08:57:29 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/23 08:57:38 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	length;
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	length = ft_strlen(s);
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (s[length] == '\t' || s[length] == '\n' || s[length] == ' ')
		length--;
	if (!(str = (char *)malloc(sizeof(char) * (length - i))))
		return (NULL);
	while (i < length)
	{
		str[k] = s[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
