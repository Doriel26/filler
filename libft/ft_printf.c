/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:56:39 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 15:57:04 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_res(int res, const char **format, va_list ap)
{
	(*format)++;
	res += ft_specifier(*format, ap);
	while (**format && !ft_strchr("sSpdDioOuUxXcC%", **format)
			&& ft_strchr(" -+#0123456789.hljz%", **format))
	{
		(*format)++;
		if (!ft_strchr(" -+#0123456789.hljzsSpdDioOuUxXcC%", **format))
		{
			(*format)--;
			break ;
		}
	}
	if (**format && ft_strchr(" -+#0123456789.hljzsSpdDioOuUxXcC%", **format))
		(*format)++;
	return (res);
}

int				ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;
	int		i;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			res++;
		}
		else
			res = ft_res(res, &format, ap);
	}
	va_end(ap);
	return (res);
}
