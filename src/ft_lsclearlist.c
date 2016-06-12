/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsclearlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 21:06:58 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_lsclearcontent(t_list *elem)
{
	t_file		*tmp;

	if ((tmp = (t_file *)(elem)->content) != NULL)
	{
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->lnk != NULL)
			free(tmp->lnk);
		if (tmp->access != NULL)
			free(tmp->access);
		if (tmp->owner != NULL)
			free(tmp->owner);
		if (tmp->group != NULL)
			free(tmp->group);
		free(tmp);
		elem->content = NULL;
	}
}

static void		ft_lscleardcontent(t_dbl *elem)
{
	t_file		*tmp;

	if ((tmp = (t_file *)elem->content) != NULL)
	{
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->lnk != NULL)
			free(tmp->lnk);
		if (tmp->access != NULL)
			free(tmp->access);
		if (tmp->owner != NULL)
			free(tmp->owner);
		if (tmp->group != NULL)
			free(tmp->group);
		free(tmp);
		elem->content = NULL;
	}
}

void			ft_lscleardlist(t_dlist **data)
{
	ft_dlist_iter(*data, &ft_lscleardcontent);
	ft_dlist_del(data);
}

void			ft_lsclearlist(t_list **data)
{
	ft_lstiter(*data, &ft_lsclearcontent);
	ft_lstclear(data);
}
