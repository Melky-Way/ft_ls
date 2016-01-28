/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_popfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 11:01:30 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/03 11:01:33 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lst_popfront(t_list **list)
{
	t_list	*tmp;

	if (*list != NULL)
	{
		tmp = (*list)->next;
		(*list)->next = NULL;
		ft_lstclear(list);
		(*list) = tmp;
	}
	return (list);
}
