/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:01:19 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/08 19:57:36 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dlist_head(t_dlist **list, void *data, size_t size)
{
	t_dbl	*new;

	if (*list == NULL && (*list = ft_dlist_new()) == NULL)
		return (-1);
	if ((new = ft_new_node(data, size)) != NULL)
	{
		if ((*list)->head != NULL)
			(*list)->head->prev = new;
		new->next = (*list)->head;
		(*list)->tail = ((*list)->tail == NULL) ? new : (*list)->tail;
		(*list)->head = new;
		(*list)->lenght++;
		return (0);
	}
	return (-1);
}
