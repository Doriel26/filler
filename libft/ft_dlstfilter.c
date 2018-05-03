/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfilter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:08:34 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:08:43 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_trimhead(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t))
{
	t_dlist *tmp;

	while ((*p)(*alst))
	{
		tmp = *alst;
		(*alst)->prev = NULL;
		*alst = (*alst)->next;
		ft_dlstdelone(&tmp, del);
	}
}

void				ft_dlstfilter(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t))
{
	t_dlist *tmp;
	t_dlist *curr;

	if (!alst)
		return ;
	ft_trimhead(alst, p, del);
	curr = (*alst) ? (*alst)->next : NULL;
	while (curr)
	{
		if (!(*p)(curr))
		{
			tmp = curr->next;
			curr->prev->next = tmp;
			curr->next->prev = curr->prev;
			ft_dlstdelone(&curr, del);
			curr = tmp;
		}
		else
			curr = curr->next;
	}
}
