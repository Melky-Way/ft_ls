/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_valdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:15:32 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:06:27 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lst_valdel(t_list *list, void *content)
{
	t_list	*tmp;
	t_list	*del;

	if (list != NULL)
	{
		tmp = list;
		del = NULL;
		while (tmp != NULL)
		{
			if (!ft_strcmp((char *)tmp->content, (char *)content))
			{
				if (del == NULL)
					list = tmp->next;
				else
					del->next = tmp->next;
				free(tmp->content);
				free(tmp);
				tmp = NULL;
			}
			del = (tmp == NULL) ? NULL : tmp;
			tmp = (tmp == NULL) ? list : tmp->next;
		}
	}
	return (list);
}
