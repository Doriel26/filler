/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:50:38 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 15:55:09 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_min(t_flag new_struct, int c)
{
	int res;

	res = 0;
	if (!ft_strchr(new_struct.flag, '-'))
	{
		while (new_struct.width > 1)
		{
			if (ft_strchr(new_struct.flag, '0'))
				ft_putchar('0');
			else
				ft_putchar(' ');
			new_struct.width--;
			res++;
		}
	}
	ft_putchar(c);
	res++;
	while (new_struct.width > 1)
	{
		ft_putchar(' ');
		new_struct.width--;
		res++;
	}
	return (res);
}

int		ft_c_maj(va_list ap)
{
	wint_t	c;
	int		res;

	res = 1;
	c = va_arg(ap, wint_t);
	return (res);
}

int		ft_c(t_flag new_struct, va_list ap)
{
	int res;

	res = 0;
	if (new_struct.specifier == 'c')
		res = ft_c_min(new_struct, va_arg(ap, int));
	else
		res = ft_c_maj(ap);
	return (res);
}
