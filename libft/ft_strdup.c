/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:21:35 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 16:21:36 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s1);
	if ((copy = (char *)malloc(sizeof(*copy) * (size + 1))) == NULL)
		return (NULL);
	copy = ft_strcpy(copy, s1);
	return (copy);
}
