/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:15:20 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/14 14:58:40 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fresh;

	i = 0;
	fresh = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	return (fresh);
}
