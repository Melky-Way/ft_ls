/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:10:49 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/27 13:10:54 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while ((*list) != NULL)
	{
		ft_putendl((*list)->content);
		(*list) = (*list)->next;
	}
	(*list) = tmp;
}
