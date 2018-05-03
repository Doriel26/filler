/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:04:37 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 15:58:25 by dchiche          ###   ########.fr       */
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

void		ft_putnbr_max(uintmax_t n)
{
	ft_putnbr_recv(n);
}
