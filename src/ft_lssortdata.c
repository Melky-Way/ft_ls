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

#define TMP ((t_file *)tmp->content)
#define POST ((t_file *)post->content)

#define ALPHASORT (!mode && ft_strcmp(TMP->name, POST->name) > 0)
#define TIMESORT (mode == 1 && (TMP->date < POST->date || \
			(POST->date == TMP->date && ft_strcmp(TMP->name, POST->name) > 0)))
#define SIZESORT (mode == 2 && TMP->size < POST->size)

static void		ft_ls_sort(t_list **data, int mode)
{
	void		*datatmp;
	t_list		*tmp;
	t_list		*post;
	size_t		i;

	tmp = *data;
	while (tmp != NULL && (post = tmp->next) != NULL)
	{
		if (ALPHASORT || TIMESORT || SIZESORT)
		{
			datatmp = tmp->content;
			i = tmp->content_size;
			tmp->content = post->content;
			tmp->content_size = post->content_size;
			post->content = datatmp;
			post->content_size = i;
			tmp = *data;
		}
		else
			tmp = post;
	}
}

static void		ft_run_list(t_list **prev, t_list **tmp)
{
	while (*tmp != NULL && (*tmp)->next != NULL)
	{
		*prev = *tmp;
		*tmp = (*tmp)->next;
	}
}

static void		ft_lstreverse(t_list **data)
{
	t_list		*tmp;
	t_list		*prev;
	t_list		*reverse;
	t_list		*start;

	tmp = *data;
	prev = NULL;
	ft_run_list(&prev, &tmp);
	start = tmp;
	prev->next = NULL;
	reverse = start;
	while (tmp != *data)
	{
		tmp = *data;
		ft_run_list(&prev, &tmp);
		prev->next = NULL;
		reverse->next = tmp;
		reverse = reverse->next;
	}
	*data = start;
}

void			ft_lssortdata(int *option, t_list **data)
{
	if (option[9])
		return ;
	ft_ls_sort(data, 0);
	if (option[6])
		ft_ls_sort(data, 2);
	else if (option[4])
		ft_ls_sort(data, 1);
	if (option[3])
		ft_lstreverse(data);
}
