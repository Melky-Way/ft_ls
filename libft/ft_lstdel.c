/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 10:23:27 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:07:08 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*to_del;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			to_del = tmp;
			tmp = tmp->next;
			ft_lstdelone(&to_del, del);
		}
		*alst = NULL;
	}
}
