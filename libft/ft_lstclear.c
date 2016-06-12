/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:36:18 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/03 18:02:40 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstclear(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		while (*list != NULL)
		{
			tmp = *list;
			*list = (*list)->next;
			if (tmp->content)
				free(tmp->content);
			free(tmp);
		}
		*list = NULL;
	}
}
