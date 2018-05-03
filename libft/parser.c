/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:34:09 by dchiche           #+#    #+#             */
/*   Updated: 2018/01/16 13:28:46 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum e_length	ft_length(const char *str)
{
	int		i;
	t_flag	new_struct;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h')
		new_struct.length = hh;
	else if (str[i] == 'h')
		new_struct.length = h;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		new_struct.length = ll;
	else if (str[i] == 'l')
		new_struct.length = l;
	else if (str[i] == 'j')
		new_struct.length = j;
	else if (str[i] == 'z')
		new_struct.length = z;
	else
		new_struct.length = none;
	return (new_struct.length);
}

t_flag			ft_struct(const char *str)
{
	int		i;
	int		j;
	t_flag	new_struct;

	i = 0;
	j = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '#'
			|| str[i] == '0' || str[i] == ' ')
		new_struct.flag[j++] = str[i++];
	new_struct.width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	new_struct.precision = (str[i] == '.') ? ft_atoi(str + ++i) : -1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	new_struct.length = ft_length(str + i);
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		i++;
	if (ft_strchr("sSpdDioOuUxXcC%", str[i]) && str[i] != '\0')
		new_struct.specifier = str[i];
	return (new_struct);
}
