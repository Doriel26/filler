/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:18:24 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/08 16:35:32 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(intmax_t nb, int i)
{
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(intmax_t n)
{
	int			i;
	uintmax_t	nb;
	char		*tab;

	nb = (n < 0) ? (uintmax_t)n * -1 : (uintmax_t)n;
	i = (n < 0) ? 2 : 1;
	i = ft_nblen(nb, i);
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb = (n < 0) ? -n : n;
	i = 0;
	while (nb >= 10)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	tab[i++] = nb + '0';
	if (n < 0)
		tab[i++] = '-';
	tab[i] = '\0';
	return (ft_strrev(tab));
}
