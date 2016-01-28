/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 10:44:15 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/19 10:47:34 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpushfront(t_list **list, void *data, size_t size)
{
	t_list	*new;

	if ((*list) == 0)
		return ((*list = ft_create_new(data, size)) != NULL);
	else
	{
		new = ft_create_new(data, size);
		if (new == NULL)
			return (0);
		new->next = *list;
		*list = new;
		return (1);
	}
}
