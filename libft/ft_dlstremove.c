/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:10:46 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:10:55 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstremove(
				t_dlist **list,
				void *dataref,
				int (*cmp)(const void *, const void *))
{
	t_dlist *tmp;

	if (!list || !cmp || !dataref)
		return (NULL);
	tmp = *list;
	while (tmp)
	{
		if (!cmp(tmp->content, dataref))
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;
			tmp->next = NULL;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
