/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:01:49 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 13:01:49 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;

	len = ft_strlen(s2);
	if (!len)
		return ((char *)s1);
	while (*s1 && (len <= n))
	{
		if (ft_memcmp(s1++, s2, len) == 0)
			return ((char *)s1 - 1);
		n--;
	}
	return (NULL);
}
