/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:34:31 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/10 11:39:16 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_type(t_flag new_struct, intmax_t n)
{
	if (new_struct.length == l)
		return ((long)n);
	if (new_struct.length == ll)
		return ((long long)n);
	if (new_struct.length == h)
		return ((short int)n);
	if (new_struct.length == hh)
		return ((signed char)n);
	if (new_struct.length == j)
		return ((intmax_t)n);
	if (new_struct.length == z)
		return ((size_t)n);
	else
		return ((int)n);
}

uintmax_t	ft_type_u(t_flag new_struct, uintmax_t n)
{
	if (new_struct.length == l)
		return ((unsigned long)n);
	if (new_struct.length == ll)
		return ((unsigned long long)n);
	if (new_struct.length == h)
		return ((unsigned short int)n);
	if (new_struct.length == hh)
		return ((unsigned char)n);
	if (new_struct.length == j)
		return ((intmax_t)n);
	if (new_struct.length == z)
		return ((size_t)n);
	else
		return ((unsigned int)n);
}
