/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstprepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:10:32 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:10:42 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstprepend(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	if (*alst)
		new->prev = (*alst)->prev;
	else
		new->prev = NULL;
	*alst = new;
}
