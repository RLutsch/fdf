/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:46:20 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:46:23 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ft_fc_mem.h>
# include <ft_fc_str.h>
# include <ft_fc_tests.h>
# include <ft_fc_print.h>
# include <ft_fc_conversion.h>

int			ft_match(char *s1, char *s2);
int			ft_nmatch(char *s1, char *s2);
void		ft_swap(int *a, int *b);
char		*ft_strrev(char *str);
#endif
