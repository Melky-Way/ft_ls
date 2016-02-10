/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 09:36:25 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:08:07 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*pointer;

	pointer = ft_memalloc(size);
	ft_memcpy(pointer, (const void*)ptr, size);
	free(ptr);
	return (pointer);
}
