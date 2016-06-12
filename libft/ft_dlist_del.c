/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:02:48 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/10 17:34:10 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlist_del(t_dlist **list)
{
	t_dbl	*tmp;
	t_dbl	*del;

	if (*list != NULL)
	{
		tmp = (*list)->head;
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->next;
			if (del->content != NULL)
				free(del->content);
			free(del);
		}
		free(*list);
	}
}
