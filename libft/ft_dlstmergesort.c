/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:11:21 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 17:14:49 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dbl	*lstsplit(t_dbl *a, int len)
{
	t_dbl		*tmp;
	int			i;

	i = 1;
	if ((tmp = a) != NULL)
	{
		while (i++ <= len && tmp != NULL)
			tmp = tmp->next;
		if (tmp != NULL)
		{
			tmp->prev->next = NULL;
			tmp->prev = NULL;
		}
	}
	return (tmp);
}

static t_dbl	*ft_mergesort(t_dbl *a, t_dbl *b, \
				int (*f)(t_dbl *lst1, t_dbl *lst2))
{
	t_dbl		*ret;
	t_dbl		*tmp;

	tmp = (*f)(a, b) ? b : a;
	if (tmp == a && a != NULL)
		a = a->next;
	else if (b != NULL)
		b = b->next;
	ret = tmp;
	while (1)
	{
		tmp->next = (*f)(a, b) ? b : a;
		tmp = tmp->next;
		if (tmp == a && a != NULL)
			a = a->next;
		else if (b != NULL)
			b = b->next;
		tmp->next = NULL;
		if (a == NULL && b == NULL)
			break ;
	}
	return (ret);
}

t_dbl			*ft_dlstmerge(t_dbl *a, int n, \
				int (*f)(t_dbl *a, t_dbl *b))
{
	t_dbl		*b;

	b = NULL;
	if (n > 2)
	{
		b = lstsplit(a, n / 2);
		b = ft_dlstmerge(b, (n + 1) / 2, (*f));
		a = ft_dlstmerge(a, (n + 1) / 2, (*f));
		return (ft_mergesort(a, b, (*f)));
	}
	if (a->next != NULL && (*f)(a, a->next))
	{
		b = a->next;
		b->next = a;
		a->prev = b;
		b->prev = NULL;
		a->next = NULL;
		return (b);
	}
	return (a);
}

t_dlist			*ft_dlstmergesort(t_dlist *a, int n, \
				int (*f)(t_dbl *a, t_dbl *b))
{
	t_dbl		*b;

	b = ft_dlstmerge(a->head, n, f);
	a->head = b;
	b->prev = NULL;
	while (b != NULL)
	{
		if (b->next != NULL)
			b->next->prev = b;
		else
			a->tail = b;
		b = b->next;
	}
	return (a);
}
