/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:11:21 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/10 13:20:20 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstsplit(t_list *a, int len)
{
	t_list		*tmp;
	t_list		*prev;
	int			i;

	i = 1;
	if ((tmp = a) != NULL)
	{
		while (i++ <= len && tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev != NULL)
			prev->next = NULL;
	}
	return (tmp);
}

static t_list	*ft_mergesort(t_list *a, t_list *b, \
				int (*f)(t_list *lst1, t_list *lst2))
{
	t_list		*ret;
	t_list		*tmp;

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

t_list			*ft_lstmergesort(t_list *a, int n, \
				int (*f)(t_list *a, t_list *b))
{
	t_list		*b;

	b = NULL;
	if (n > 2)
	{
		b = lstsplit(a, n / 2);
		b = ft_lstmergesort(b, (n + 1) / 2, (*f));
		a = ft_lstmergesort(a, (n + 1) / 2, (*f));
		return (ft_mergesort(a, b, (*f)));
	}
	if (a->next != NULL && (*f)(a, a->next))
	{
		b = a->next;
		b->next = a;
		a->next = NULL;
		return (b);
	}
	return (a);
}
