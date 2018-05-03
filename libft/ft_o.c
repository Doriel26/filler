/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 21:46:58 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 16:52:03 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_min_o(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = (ft_strchr(new_struct.flag, '#') && nb != 0) ? len + 1 : len;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	if (tmp > len && nb != 0)
		ft_putchar('0');
	while (new_struct.precision-- > len)
		ft_putchar('0');
	if (new_struct.width <= 0 && new_struct.precision == 0 && nb == 0)
		return (len + diff + diffwidth);
	else if (new_struct.precision <= 0 && nb == 0)
		tmp = tmp + 0;
	else
		ft_putnbr_base(nb, "01234567");
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar(' ');
	if (new_struct.precision == 0 && nb == 0)
		ft_putchar(' ');
	while (new_struct.width-- > diff && nb == 0)
		ft_putchar(' ');
	return (tmp + diff + diffwidth);
}

int		ft_zero_o(t_flag new_struct, uintmax_t nb, int len)
{
	int diff;
	int diffwidth;
	int tmp;

	diff = (new_struct.precision > len) ? new_struct.precision - len : 0;
	tmp = (ft_strchr(new_struct.flag, '#') && nb != 0) ? len + 1 : len;
	diffwidth = (new_struct.width > tmp + diff) ?
		new_struct.width - (tmp + diff) : 0;
	if (tmp > len && nb != 0)
		ft_putchar('0');
	while (new_struct.width-- > diff + tmp && nb != 0)
		ft_putchar('0');
	while (new_struct.width-- > diff && nb == 0)
		ft_putchar(' ');
	ft_putnbr_base(nb, "01234567");
	return (tmp + diff + diffwidth);
}

int		ft_classic_o(t_flag n_s, uintmax_t nb, int len, int tmp)
{
	int dif;
	int diffwidth;
	int tmpwidth;

	tmpwidth = n_s.width;
	dif = (n_s.precision > len) ? n_s.precision - len : 0;
	diffwidth = (n_s.width > tmp + dif) ? n_s.width - (tmp + dif) : 0;
	while ((n_s.width-- > dif + tmp && nb != 0) || (n_s.width > dif && nb == 0))
		ft_putchar(' ');
	if (tmp > len && nb != 0)
		ft_putchar('0');
	while (n_s.precision > len)
	{
		ft_putchar('0');
		n_s.precision--;
	}
	if (tmpwidth <= 0 && n_s.precision == 0 && nb == 0
			&& !ft_strchr(n_s.flag, '#'))
		return (dif + diffwidth);
	if (tmpwidth > 0 && n_s.precision == 0 && nb == 0
			&& !ft_strchr(n_s.flag, '#'))
		ft_putchar(' ');
	else
		ft_putnbr_base(nb, "01234567");
	return (tmp + dif + diffwidth);
}

int		ft_o(t_flag new_struct, va_list ap)
{
	uintmax_t	nb;
	int			len;
	int			res;
	int			tmp;

	if (new_struct.specifier == 'O')
		new_struct.length = l;
	nb = ft_type_u(new_struct, va_arg(ap, uintmax_t));
	len = ft_nlen_base(nb, 8);
	tmp = (ft_strchr(new_struct.flag, '#') && nb != 0) ? len + 1 : len;
	if (ft_strchr(new_struct.flag, '-'))
		res = ft_min_o(new_struct, nb, len);
	else if (ft_strchr(new_struct.flag, '0') && new_struct.precision == -1)
		res = ft_zero_o(new_struct, nb, len);
	else
		res = ft_classic_o(new_struct, nb, len, tmp);
	return (res);
}
