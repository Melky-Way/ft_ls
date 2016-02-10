/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsclearlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2015/04/15 17:37:03 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_lsclearcontent(t_file *content)
{
	if (content != NULL)
	{
		if (content->access != NULL)
			free(content->access);
		if (content->owner != NULL)
			free(content->owner);
		if (content->group != NULL)
			free(content->group);
		if (content->name != NULL)
			free(content->name);
		free(content);
	}
}

void			ft_lsclearlist(t_list **data)
{
	t_list		*tmp;

	if (*data != NULL)
	{
		tmp = (t_list *)*data;
		while (tmp != NULL)
		{
			ft_lsclearcontent((t_file *)tmp->content);
			tmp->content = NULL;
			tmp = tmp->next;
		}
		ft_lstclear(data);
	}
}
