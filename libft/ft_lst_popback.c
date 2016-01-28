/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_popback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:51:41 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/03 10:51:49 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lst_popback(t_list **list)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		ft_lstclear(&tmp);
		prev->next = NULL;
	}
	return (list);
}
