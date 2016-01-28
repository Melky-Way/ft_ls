/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_valdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:15:32 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:05:29 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_dlist_valdel_bis(t_dlist *list, t_dbl *tmp)
{
	t_dbl	*del;

	del = tmp;
	tmp = tmp->next;
	if (del->next == NULL)
	{
		list->tail = del->prev;
		list->tail->next = NULL;
	}
	else if (del->prev == NULL)
	{
		list->head = del->next;
		list->head->next = NULL;
	}
	else
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
	}
	free(del->content);
	free(del);
}

t_dlist			*ft_dlist_valdel(t_dlist *list, void *content)
{
	t_dbl	*tmp;

	if (list != NULL)
	{
		tmp = list->head;
		while (tmp != NULL)
		{
			if (!ft_strcmp((char *)tmp->content, (char *)content))
			{
				ft_dlist_valdel_bis(list, tmp);
				list->lenght--;
			}
			else
				tmp = tmp->next;
		}
	}
	return (list);
}
