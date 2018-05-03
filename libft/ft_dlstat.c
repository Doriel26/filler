/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:07:19 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:07:28 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstat(t_dlist *head, size_t index)
{
	size_t i;

	i = 0;
	while (head && i < index)
	{
		head = head->next;
		i++;
	}
	return (head);
}
