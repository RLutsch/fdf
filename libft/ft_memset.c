/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:56:19 by rlutsch           #+#    #+#             */
/*   Updated: 2016/05/23 10:49:52 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
    size_t			i;
    char			*temp;
    unsigned char	c_c;
    
    i = 0;
    c_c = c;
    temp = (char *)b;
    while (i < len)
    {
        temp[i] = c_c;
        i++;
    }
    return (b);
}
