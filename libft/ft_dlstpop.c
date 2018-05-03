/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:10:10 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:10:21 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstpop(t_dlist **alst)
{
	t_dlist	*res;

	if (!alst || !*alst)
		return (NULL);
	if ((*alst)->prev)
		(*alst)->prev->next = (*alst)->next;
	res = *alst;
	*alst = (*alst)->next;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
