/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:51:22 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/27 11:51:23 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	content_size = content ? content_size : 0;
	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((elem->content = malloc(sizeof(content_size))) == NULL)
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
	}
	else
		elem->content = NULL;
	elem->content_size = content_size;
	elem->next = NULL;
	return (elem);
}
