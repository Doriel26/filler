/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_or_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:59:25 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/18 20:19:21 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_min_d(t_flag n_s, intmax_t nb, int len, int tmp)
{
	int dif;
	int diffwidth;

	dif = (n_s.precision > len) ? n_s.precision - len : 0;
	diffwidth = (n_s.width > tmp + dif) ? n_s.width - (tmp + dif) : 0;
	if (ft_strchr(n_s.flag, '+') && nb >= 0)
		ft_putchar('+');
	else if (ft_strchr(n_s.flag, ' ') && nb >= 0)
		ft_putchar(' ');
	if (nb < 0)
		ft_putchar('-');
	nb = (nb < 0) ? (uintmax_t)nb * -1 : (uintmax_t)nb;
	while (n_s.precision-- > len)
		ft_putchar('0');
	if (n_s.width <= 0 && n_s.precision == -1 && nb == 0)
		return (len + dif + diffwidth);
	else
		ft_putnbr_max(nb);
	while (n_s.width-- > dif + tmp && nb != 0)
		ft_putchar(' ');
	if (n_s.precision == -1 && nb == 0)
		ft_putchar(' ');
	while (n_s.width-- > dif && nb == 0)
		ft_putchar(' ');
	return (tmp + dif + diffwidth);
}

int		ft_zero_d(t_flag n_s, intmax_t nb, int len, int tmp)
{
	int dif;
	int diffwidth;
	int tmprecision;

	tmprecision = n_s.precision;
	dif = (n_s.precision > len) ? n_s.precision - len : 0;
	diffwidth = (n_s.width > tmp + dif) ? n_s.width - (tmp + dif) : 0;
	if (ft_strchr(n_s.flag, '+') && nb >= 0)
		ft_putchar('+');
	else if (ft_strchr(n_s.flag, ' '))
		ft_putchar(' ');
	if (nb < 0)
		ft_putchar('-');
	while (n_s.precision-- > len)
		ft_putchar(' ');
	while (n_s.width-- > dif + tmp)
		(nb == 0 && tmprecision == 0) ? ft_putchar(' ') : ft_putchar('0');
	if (nb < 0)
		nb = nb * -1;
	if (nb == 0 && tmprecision == 0)
		ft_putchar(' ');
	else
		ft_putnbr_max(nb);
	return (tmp + dif + diffwidth);
}

void	ft_aux(t_flag n_s, intmax_t nb)
{
	if (ft_strchr(n_s.flag, '+') && nb >= 0)
		ft_putchar('+');
	else if (ft_strchr(n_s.flag, ' ') && nb >= 0)
		ft_putchar(' ');
	if (nb < 0)
		ft_putchar('-');
}

int		ft_classic_d(t_flag n_s, intmax_t nb, int len, int tmp)
{
	int			dif;
	int			diffwidth;

	dif = (n_s.precision > len) ? n_s.precision - len : 0;
	diffwidth = (n_s.width > tmp + dif) ? n_s.width - (tmp + dif) : 0;
	n_s.width -= (nb < 0 && n_s.width > len && n_s.precision > len) ? 1 : 0;
	while (n_s.width-- > dif + tmp && nb != 0)
		ft_putchar(' ');
	if (n_s.width >= 0 && n_s.precision == 0 && nb == 0)
		ft_putchar(' ');
	diffwidth += (n_s.width >= 0 && n_s.precision == 0 && nb == 0) ? 1 : 0;
	while (n_s.width-- > dif && nb == 0)
		ft_putchar(' ');
	ft_aux(n_s, nb);
	n_s.precision += (nb < 0 && n_s.precision >= 0 && n_s.width <= 0) ? 1 : 0;
	tmp += (nb < 0 && n_s.precision >= 0 && n_s.precision > len + 1) ? 1 : 0;
	if (nb < 0 && n_s.precision > len && n_s.width > 0)
		ft_putchar('0');
	while (n_s.precision-- > len)
		ft_putchar('0');
	if (n_s.precision == -1 && nb == 0)
		return ((n_s.width == 0) ? len + dif + diffwidth : dif + diffwidth);
	nb = (nb < 0) ? (uintmax_t)nb * -1 : nb;
	ft_putnbr_max(nb);
	return (tmp + dif + diffwidth);
}

int		ft_d_or_i(t_flag new_struct, va_list ap)
{
	intmax_t	nb;
	int			len;
	int			res;
	int			tmp;

	if (new_struct.specifier == 'D')
		new_struct.length = l;
	nb = ft_type(new_struct, va_arg(ap, intmax_t));
	len = ft_nlen(nb);
	tmp = ((ft_strchr(new_struct.flag, '+') || ft_strchr(new_struct.flag, ' '))
			&& nb >= 0) ? len + 1 : len;
	if (ft_strchr(new_struct.flag, '-'))
		res = ft_min_d(new_struct, nb, len, tmp);
	else if (ft_strchr(new_struct.flag, '0'))
		res = ft_zero_d(new_struct, nb, len, tmp);
	else
		res = ft_classic_d(new_struct, nb, len, tmp);
	return (res);
}
