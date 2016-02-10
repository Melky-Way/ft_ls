/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 17:25:14 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/19 17:25:19 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_swap(t_list *lst1, t_list *lst2)
{
	void	*content;
	size_t	size;

	if (lst1 && lst2)
	{
		content = lst1->content;
		size = lst1->content_size;
		lst1->content = lst2->content;
		lst1->content_size = lst2->content_size;
		lst2->content = content;
		lst2->content_size = size;
	}
}
