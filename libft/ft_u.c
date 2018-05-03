/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:48:15 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 15:49:14 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_min_u(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = len;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	if (tmp > len && nb > 0)
		ft_putchar('+');
	while (new_struct.precision-- > len)
		ft_putchar('0');
	if (new_struct.width <= 0 && new_struct.precision == 0 && nb == 0)
		return (len + diff + diffwidth);
	else if (new_struct.precision <= 0 && nb == 0)
		tmp = tmp + 0;
	else
		ft_putnbr_max_u(nb);
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar(' ');
	if (new_struct.precision == 0 && nb == 0)
		ft_putchar(' ');
	while (new_struct.width-- > diff && nb == 0)
		ft_putchar(' ');
	return (tmp + diff + diffwidth);
}

int		ft_zero_u(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = len;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	if (tmp > len && nb > 0)
		ft_putchar('+');
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar('0');
	while (new_struct.width-- > diff && nb == 0)
		ft_putchar(' ');
	ft_putnbr_max_u(nb);
	return (tmp + diff + diffwidth);
}

int		ft_classic_u(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = len;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar(' ');
	while (new_struct.width-- > diff && nb == 0)
		ft_putchar(' ');
	if (tmp > len && nb > 0)
		ft_putchar('+');
	while (new_struct.precision-- > len)
		ft_putchar('0');
	if (new_struct.width == 0 && new_struct.precision == 0 && nb == 0)
		return (len + diff + diffwidth);
	else if (new_struct.precision == -1 && nb == 0)
		return (diff + diffwidth);
	else
		ft_putnbr_max_u(nb);
	return (tmp + diff + diffwidth);
}

int		ft_u(t_flag new_struct, va_list ap)
{
	uintmax_t	nb;
	int			len;
	int			res;

	if (new_struct.specifier == 'U')
		new_struct.length = l;
	nb = ft_type_u(new_struct, va_arg(ap, uintmax_t));
	len = ft_nlen_base(nb, 10);
	if (ft_strchr(new_struct.flag, '-'))
		res = ft_min_u(new_struct, nb, len);
	else if (ft_strchr(new_struct.flag, '0') && new_struct.precision == -1)
		res = ft_zero_u(new_struct, nb, len);
	else
		res = ft_classic_u(new_struct, nb, len);
	return (res);
}
