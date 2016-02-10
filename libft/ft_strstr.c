/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:33:32 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 12:33:32 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	n;

	n = ft_strlen(s2);
	if (!n)
		return ((char *)s1);
	while (*s1)
	{
		if (ft_memcmp(s1++, s2, n) == 0)
			return ((char *)s1 - 1);
	}
	return (NULL);
}
