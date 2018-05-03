/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:45:49 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 17:00:14 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_aux(t_flag new_struct, char *str, int len, int res)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar(str[i]);
		i++;
		res++;
	}
	while (new_struct.width-- > len)
	{
		ft_putchar(' ');
		res++;
	}
	return (res);
}

int		ft_s_min(t_flag new_struct, va_list ap)
{
	char	*str;
	int		i;
	int		len;
	int		res;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	i = 0;
	res = 0;
	len = ft_strlen(str);
	if (len > new_struct.precision && new_struct.precision >= 0)
		len = new_struct.precision;
	if (!ft_strchr(new_struct.flag, '-'))
	{
		while (new_struct.width-- > len)
		{
			if (ft_strchr(new_struct.flag, '0'))
				ft_putchar('0');
			else
				ft_putchar(' ');
			res++;
		}
	}
	return (ft_s_aux(new_struct, str, len, res));
}

int		ft_s(t_flag new_struct, va_list ap)
{
	int		res;
	wchar_t	*str;

	res = 0;
	if (new_struct.specifier == 's')
		res = ft_s_min(new_struct, ap);
	else
		str = va_arg(ap, wchar_t *);
	return (res);
}
