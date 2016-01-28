/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:33:07 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:07:46 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl		*ft_new_node(void *data, size_t size)
{
	t_dbl	*new;

	if ((new = (t_dbl *)malloc(sizeof(t_dbl))) == NULL)
		return (NULL);
	new->prev = NULL;
	new->content = data;
	new->size = size;
	new->next = NULL;
	return (new);
}
