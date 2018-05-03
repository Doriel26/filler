/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:56:31 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 18:56:46 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_dlst_to_tab(t_dlist *list)
{
	size_t	i;
	size_t	len;
	void	**res;

	len = ft_dlstlen(list);
	if (!(res = (void **)malloc(sizeof(void *) * (len + 1))))
		return (NULL);
	i = 0;
	while (list)
	{
		res[i] = list->content;
		list = list->next;
		i += 1;
	}
	res[i] = NULL;
	return (res);
}
