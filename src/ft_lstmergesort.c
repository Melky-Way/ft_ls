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

/*t_list		*ft_lstaddsort(t_list *lst, t_list new, \
			int (*f)(void *cnt1, void *cnt2))
{
	t_list	*tmp;
	t_list	*prev;

	if (new == NULL)
		return (NULL);
	if (lst == NULL)
		return (new);
	if ((tmp == lst) != NULL)
	{
		while (!(*f)(tmp->content, new->content) && tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL)
		{
			new->next = tmp;
			return (new);
		}
		prev->next = new;
		new->next = tmp;
	}
	return (lst);
}*/

static t_list	*lstsplit(t_list *a, int len)
{
	t_list		*tmp;
	t_list		*prev;
	int			i;

	i = 1;
	if ((tmp = a) != NULL)
	{
		while (i++ < len && tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev != NULL)
			prev->next = NULL;
	}
	return (tmp);
}

static t_list	*mergesort(t_list *a, t_list *b, \
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

t_list			*ft_lstmergesort(t_list *a, int n \
				(*f)(t_list *a, t_list *b))
{
	t_list		*b;

	if (n > 2)
	{
		b = lstsplit(a, n / 2, (*f));
		b = ft_lstmergesort(b, n / 2, (*f));
		a = ft_lstmergesort(a, n / 2, (*f));
		return (mergesort(a, b, (*f)));
	}
	if (a->next != NULL && (*f)(a->content, a->next->content))
	{
		b = a;
		a = a->next;
		a->next = b;
		b->next = NULL;
	}
	return (b);
}
