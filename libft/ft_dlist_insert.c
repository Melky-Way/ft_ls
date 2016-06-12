/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:01:45 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/08 20:03:06 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_dlist_bdy(t_dlist *list, t_dbl *tmp, t_dbl *new)
{
	if (new != NULL)
	{
		tmp->prev->next = new;
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev = new;
		list->lenght++;
	}
}

t_dlist			*ft_dlist_insert(t_dlist *list, void *data, int pos, \
				size_t size)
{
	t_dbl		*temp;
	int			i;

	i = 1;
	if (list == NULL || (temp = list->head) == NULL)
		return (NULL);
	while (temp != NULL && i++ <= pos)
		temp = temp->next;
	if (temp == NULL)
		return (list);
	if (temp->next == NULL)
		ft_dlist_tail(&list, data, size);
	else if (temp->prev == NULL)
		ft_dlist_head(&list, data, size);
	else
		ft_dlist_bdy(list, temp, ft_new_node(data, size));
	return (list);
}
