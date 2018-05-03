/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:09:20 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/12 15:06:44 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_specifier(const char *str, va_list ap)
{
	int		res;
	t_flag	new_struct;

	res = 0;
	new_struct = ft_struct(str);
	if (new_struct.specifier == 's' || new_struct.specifier == 'S')
		res += ft_s(new_struct, ap);
	if (new_struct.specifier == 'p')
		res += ft_p(new_struct, ap);
	if (new_struct.specifier == 'd' || new_struct.specifier == 'i'
			|| new_struct.specifier == 'D')
		res += ft_d_or_i(new_struct, ap);
	if (new_struct.specifier == 'o' || new_struct.specifier == 'O')
		res += ft_o(new_struct, ap);
	if (new_struct.specifier == 'u' || new_struct.specifier == 'U')
		res += ft_u(new_struct, ap);
	if (new_struct.specifier == 'x')
		res += ft_x(new_struct, ap);
	if (new_struct.specifier == 'X')
		res += ft_x_maj(new_struct, ap);
	if (new_struct.specifier == 'c' || new_struct.specifier == 'C')
		res += ft_c(new_struct, ap);
	if (new_struct.specifier == '%')
		res += ft_c_min(new_struct, '%');
	return (res);
}
