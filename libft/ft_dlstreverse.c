/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:45:24 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/08 20:25:21 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstreverse(t_dlist *data)
{
	t_dbl		*tmp;
	t_dbl		*elem;

	if (data == NULL || data->lenght <= 1)
		return (data);
	tmp = data->head;
	data->head = data->tail;
	data->tail = tmp;
	elem = tmp;
	while (elem != NULL)
	{
		tmp = elem->prev;
		elem->prev = elem->next;
		elem->next = tmp;
		elem = elem->prev;
	}
	return (data);
}
