/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swaptail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:48:20 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/03 10:48:24 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_swaptail(t_list *swap, t_list **target)
{
	t_list	*tmp;

	tmp = *target;
	if (*target != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->content = swap->content;
		tmp->content_size = swap->content_size;
	}
}
