/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_softcopy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:44:30 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/03 10:44:36 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_softcopy(t_list *list)
{
	t_list	*tmp;
	t_list	*newlist;
	t_list	*returnvalue;

	if ((tmp = list) != NULL)
	{
		newlist = ft_create_new(tmp->content, tmp->content_size);
		returnvalue = newlist;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			newlist->next = ft_create_new(tmp->content, tmp->content_size);
			newlist = newlist->next;
			tmp = tmp->next;
		}
		return (returnvalue);
	}
	else
		return (NULL);
}
