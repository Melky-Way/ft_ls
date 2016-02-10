/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:43:11 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:06:48 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	if (lst)
	{
		ret = ft_lstnew(lst->content, lst->content_size);
		ret = (*f)(ret);
		tmp = ret;
		lst = lst->next;
		while (lst)
		{
			tmp->next = ft_lstnew(lst->content, lst->content_size);
			tmp->next = (*f)(lst);
			tmp = tmp->next;
			lst = lst->next;
		}
		return (ret);
	}
	return (NULL);
}
