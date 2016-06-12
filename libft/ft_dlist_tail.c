/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:01:00 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/08 20:21:02 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dlist_tail(t_dlist **list, void *data, size_t size)
{
	t_dbl	*new;

	if (*list == NULL && (*list = ft_dlist_new()) == NULL)
		return (-1);
	if ((new = ft_new_node(data, size)) != NULL)
	{
		(*list)->head = ((*list)->tail == NULL) ? new : (*list)->head;
		new->prev = (*list)->tail;
		if ((*list)->tail != NULL)
			(*list)->tail->next = new;
		(*list)->tail = new;
		(*list)->lenght++;
		return (0);
	}
	return (-1);
}
