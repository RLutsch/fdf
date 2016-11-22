/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 10:58:20 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/14 14:57:42 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	i = 0;
	fresh = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	return (fresh);
}
