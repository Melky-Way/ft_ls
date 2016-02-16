/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssortdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 20:08:15 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*ft_lstreverse(t_list *data, t_list *next)
{
	t_list		*tmp;

	if (next == NULL)
		return (data);
	tmp = next->next;
	next->next = data;
	if ((void *)data->next == (void *)next)
		data->next = NULL;
	if (tmp != NULL)
		return (ft_lstreverse(next, tmp));
	return (next);
}

static int		ft_sortalpha(t_list *a, t_list *b)
{
	t_file		*tmp1;
	t_file		*tmp2;

	if (a != NULL && b != NULL)
	{
		tmp1 = (t_file *)a->content;
		tmp2 = (t_file *)b->content;
		return ((ft_strcmp(tmp1->name, tmp2->name) > 0));
	}
	if (a == NULL && b)
		return (1);
	return (0);
}

static int		ft_sorttime(t_list *a, t_list *b)
{
	t_file		*tmp1;
	t_file		*tmp2;

	if (a != NULL && b != NULL)
	{
		tmp1 = (t_file *)a->content;
		tmp2 = (t_file *)b->content;
		return ((tmp1->date < tmp2->date || (tmp2->date == tmp1->date && \
				ft_strcmp(tmp1->name, tmp2->name) > 0)));
	}
	if (a == NULL && b)
		return (1);
	return (0);
}

static int		ft_sortsize(t_list *a, t_list *b)
{
	t_file		*tmp1;
	t_file		*tmp2;

	if (a != NULL && b != NULL)
	{
		tmp1 = (t_file *)a->content;
		tmp2 = (t_file *)b->content;
		return ((tmp1->size < tmp2->size));
	}
	if (a == NULL && b)
		return (1);
	return (0);
}

void			ft_lssortdata(int *option, t_list **data)
{
	int			len;

	len = (*data == NULL) ? 0 : ft_lstsize(*data);
	if (option[9])
		return ;
	*data = ft_lstmergesort(*data, len, &ft_sortalpha);
	if (option[6])
		*data = ft_lstmergesort(*data, len, &ft_sortsize);
	else if (option[4])
		*data = ft_lstmergesort(*data, len, &ft_sorttime);
	if (option[3] && *data != NULL)
		*data = ft_lstreverse(*data, (*data)->next);
}
