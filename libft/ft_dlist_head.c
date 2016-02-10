/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:01:19 by msoudan           #+#    #+#             */
/*   Updated: 2013/12/26 14:01:20 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_head(t_dlist *list, void *data, size_t size)
{
	t_dbl	*new;

	if (list != NULL)
	{
		if ((new = ft_new_node(data, size)) != NULL)
		{
			new->next = (list->tail == NULL) ? NULL : list->head;
			list->tail = (list->tail == NULL) ? new : list->tail;
			if (list->head != NULL)
				list->head->prev = new;
			list->head = new;
			list->lenght++;
		}
	}
	return (list);
}
