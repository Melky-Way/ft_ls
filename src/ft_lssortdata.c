/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssortdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 16:59:45 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define SAME_TIME (tmp2->date == tmp1->date && tmp2->nano == tmp1->nano)

static int		ft_sortalpha(t_dbl *a, t_dbl *b)
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

static int		ft_sorttime(t_dbl *a, t_dbl *b)
{
	t_file		*tmp1;
	t_file		*tmp2;

	if (a != NULL && b != NULL)
	{
		tmp1 = (t_file *)a->content;
		tmp2 = (t_file *)b->content;
		return ((tmp1->date < tmp2->date || \
				(tmp2->date == tmp1->date && tmp1->nano < tmp2->nano) || \
				(SAME_TIME && ft_strcmp(tmp1->name, tmp2->name) > 0)));
	}
	if (a == NULL && b)
		return (1);
	return (0);
}

static int		ft_sortsize(t_dbl *a, t_dbl *b)
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

void			ft_lssortdata(int *option, t_dlist **data)
{
	int			len;

	if (*data == NULL)
		return ;
	len = (*data)->lenght;
	if (option[9])
		return ;
	*data = ft_dlstmergesort(*data, len, &ft_sortalpha);
	if (option[6])
		*data = ft_dlstmergesort(*data, len, &ft_sortsize);
	else if (option[4] || (option[5] == 'u' && !option[2]))
		*data = ft_dlstmergesort(*data, len, &ft_sorttime);
	if (option[3] && *data != NULL)
		*data = ft_dlstreverse(*data);
}
