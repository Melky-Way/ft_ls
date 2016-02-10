/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:01:45 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:05:12 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlist_bdy(t_dlist *list, t_dbl *tmp, void *data, size_t size)
{
	t_dbl	*new;

	new = ft_new_node(data, size);
	if (new != NULL)
	{
		tmp->prev->next = new;
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev = new;
		list->lenght++;
	}
}

t_dlist		*ft_dlist_insert(t_dlist *list, void *data, int pos, size_t size)
{
	t_dbl	*temp;
	int		i;

	i = 1;
	if (list != NULL)
	{
		temp = list->head;
		while (temp != NULL && i <= pos)
		{
			temp = temp->next;
			i++;
		}
		if (temp == NULL)
			return (list);
		if (temp->next == NULL)
			list = ft_dlist_tail(list, data, size);
		else if (temp->prev == NULL)
			list = ft_dlist_head(list, data, size);
		else
			ft_dlist_bdy(list, temp, data, size);
	}
	return (list);
}
