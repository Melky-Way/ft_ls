/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 10:47:45 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/19 10:55:14 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpushback(t_list **list, void *data, size_t size)
{
	t_list	*end_list;

	if ((*list) == 0)
		return ((*list = ft_create_new(data, size)) != NULL);
	else
	{
		end_list = *list;
		while (end_list->next != NULL)
			end_list = end_list->next;
		return ((end_list->next = ft_create_new(data, size)) != NULL);
	}
}
