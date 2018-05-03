/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:26:26 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:05:47 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

enum				e_length
{
	hh, h, l, ll, j, z, none
};

typedef struct		s_flag
{
	char			specifier;
	char			flag[5];
	int				width;
	int				precision;
	enum e_length	length;
}					t_flag;

int					ft_printf(const char *format, ...);
int					ft_specifier(const char *str, va_list ap);
intmax_t			ft_type(t_flag new_struct, intmax_t n);
uintmax_t			ft_type_u(t_flag new_struct, uintmax_t n);
int					ft_c(t_flag new_struct, va_list ap);
int					ft_c_min(t_flag new_struct, int c);
int					ft_s(t_flag new_struct, va_list ap);
int					ft_d_or_i(t_flag new_struct, va_list ap);
int					ft_u(t_flag new_struct, va_list ap);
int					ft_x(t_flag new_struct, va_list ap);
int					ft_x_maj(t_flag new_struct, va_list ap);
int					ft_o(t_flag new_struct, va_list ap);
int					ft_p(t_flag new_struct, va_list ap);
enum e_length		ft_length(const char *str);
t_flag				ft_struct(const char *str);
char				*ft_flag(const char *str);

#endif
