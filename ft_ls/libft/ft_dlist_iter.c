/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 19:12:08 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/10 19:12:15 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlist_iter(t_dlist *lst, void (*f)(t_dbl *elem))
{
	t_dbl	*tmp;

	if (lst && (tmp = lst->head) != NULL)
	{
		while (tmp)
		{
			(*f)(tmp);
			tmp = tmp->next;
		}
	}
}
