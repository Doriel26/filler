/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:06:59 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:07:12 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	new->prev = *alst;
	if (*alst)
		new->next = (*alst)->next;
	else
		new->next = NULL;
	*alst = new;
}
