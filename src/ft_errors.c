/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:40:05 by rlutsch           #+#    #+#             */
/*   Updated: 2016/11/25 10:40:07 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_print.h>
#include <stdlib.h>
#include <string.h>

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

void	ft_assert(int check, char *str)
{
	if (!check)
		ft_exit(str);
}

void	ft_strerror(int errnum)
{
	strerror(errnum);
	exit(0);
}

void	ft_error(char *line, int lnb, char *str)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\033[0m\nError on line ", 2);
	ft_putnbr_fd(lnb, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("\033[0m", 2);
	exit(0);
}
