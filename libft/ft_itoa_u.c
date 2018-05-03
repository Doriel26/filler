/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:53:51 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/08 16:55:35 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(uintmax_t nb, int i)
{
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_u(uintmax_t n)
{
	int			i;
	uintmax_t	nb;
	char		*tab;

	nb = n;
	i = 1;
	i = ft_nblen(nb, i);
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb = n;
	i = 0;
	while (nb >= 10)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	tab[i++] = nb + '0';
	tab[i] = '\0';
	return (ft_strrev(tab));
}
