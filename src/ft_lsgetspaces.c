/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 21:56:02 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define TMP ((t_file *)tmp->content)

void			ft_lsgetspaces(int *array, t_list **data)
{
	t_list		*tmp;
	int			i;

	tmp = (t_list *)*data;
	while (tmp != NULL)
	{
		array[0] = array[0] < TMP->links ? TMP->links : array[0];
		i = (int)ft_strlen(TMP->owner);
		array[1] = array[1] < i ? i : array[1];
		i = (int)ft_strlen(TMP->group);
		array[2] = array[2] < i ? i : array[2];
		array[3] = array[3] < TMP->size ? TMP->size : array[3];
		tmp = tmp->next;
	}
	array[0] = ft_lsgetsize(array[0]);
	array[3] = ft_lsgetsize(array[3]);
}
