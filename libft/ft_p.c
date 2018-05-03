/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:49:28 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 16:54:48 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_min_p(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = len + 2;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	ft_putstr("0x");
	while (new_struct.precision-- > len)
		ft_putchar('0');
	if (new_struct.width <= 0 && new_struct.precision == 0 && nb == 0)
		return (len + diff + diffwidth);
	else
		ft_putnbr_base(nb, "0123456789abcdef");
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar(' ');
	if (new_struct.precision == 0 && nb == 0)
		ft_putchar(' ');
	while (new_struct.width-- >= tmp && nb == 0)
		ft_putchar(' ');
	return (tmp + diff + diffwidth);
}

int		ft_zero_p(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = len + 2;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	ft_putstr("0x");
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar('0');
	while (new_struct.width-- > diff && nb == 0)
		ft_putchar(' ');
	ft_putnbr_base(nb, "0123456789abcdef");
	return (tmp + diff + diffwidth);
}

int		ft_classic_p(t_flag new_struct, uintmax_t nb, int len, int tmp)
{
	int diff;
	int diffwidth;
	int tmpwidth;

	tmpwidth = new_struct.width;
	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	while ((new_struct.width-- > diff + tmp && nb != 0)
			|| (new_struct.width > diffwidth && nb == 0))
		ft_putchar(' ');
	ft_putstr("0x");
	while (new_struct.precision > len)
	{
		ft_putchar('0');
		new_struct.precision--;
	}
	if (tmpwidth == 0 && new_struct.precision == 0 && nb == 0)
		return (2 + diff + diffwidth);
	else if (tmpwidth > 0 && new_struct.precision == 0 && nb == 0
			&& !ft_strchr(new_struct.flag, '#'))
		ft_putchar(' ');
	else
		ft_putnbr_base(nb, "0123456789abcdef");
	return (tmp + diff + diffwidth);
}

int		ft_p(t_flag new_struct, va_list ap)
{
	uintmax_t	nb;
	int			len;
	int			res;
	int			tmp;

	nb = (uintmax_t)va_arg(ap, void *);
	len = ft_nlen_base(nb, 16);
	tmp = len + 2;
	if (ft_strchr(new_struct.flag, '-'))
		res = ft_min_p(new_struct, nb, len);
	else if (ft_strchr(new_struct.flag, '0') && new_struct.precision == -1)
		res = ft_zero_p(new_struct, nb, len);
	else
		res = ft_classic_p(new_struct, nb, len, tmp);
	return (res);
}
