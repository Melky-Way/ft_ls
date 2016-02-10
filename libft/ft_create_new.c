/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 11:10:06 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/19 11:12:26 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_create_new(void *content, size_t size)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->next = NULL;
		new->content = content;
		new->content_size = size;
	}
	return (new);
}
