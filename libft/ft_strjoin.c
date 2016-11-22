/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 13:05:16 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/20 09:09:37 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		l;
	char	*t;

	t = (char *)malloc(sizeof(char) * sizeof(s2) + ft_strlen(s1));
	i = 0;
	l = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[i])
	{
		t[i] = s2[l];
		i++;
		l++;
	}
	t[i] = '\0';
	return (t);
}
