/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:12:38 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/10 11:41:44 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recv(unsigned long long n)
{
	if (n >= 10)
	{
		ft_putnbr_recv(n / 10);
		ft_putnbr_recv(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void		ft_putnbr_max_u(uintmax_t n)
{
	ft_putnbr_recv(n);
}
