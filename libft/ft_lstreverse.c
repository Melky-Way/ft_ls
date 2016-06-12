/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:45:24 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 17:12:11 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstreverse_core(t_list *data, t_list *next)
{
	t_list		*tmp;

	if (next == NULL)
		return (data);
	tmp = next->next;
	next->next = data;
	if ((void *)data->next == (void *)next)
		data->next = NULL;
	if (tmp != NULL)
		return (ft_lstreverse_core(next, tmp));
	return (next);
}

t_list			*ft_lstreverse(t_list *data)
{
	return (ft_lstreverse_core(data, data->next));
}
