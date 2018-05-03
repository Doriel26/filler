/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:09:18 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:09:30 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlink(void *content, size_t content_size)
{
	t_dlist *list;

	if (!(list = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	list->content_size = (content) ? content_size : 0;
	list->content = content;
	return (list);
}
