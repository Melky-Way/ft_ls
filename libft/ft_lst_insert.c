/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:01:45 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:10:54 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_insert(t_list *list, void *data, int pos, size_t size)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*new;
	int		i;

	i = 1;
	if ((temp = list) == NULL)
		return (NULL);
	while (temp != NULL && i++ <= pos)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		ft_lstpushback(&list, data, size);
	else if (i == pos && prev == NULL)
		ft_lstpushfront(&list, data, size);
	else if (i == pos && (new = ft_create_new(data, size)) != NULL)
	{
		prev->next = new;
		new->next = temp;
	}
	return (list);
}
