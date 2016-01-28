/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:55:45 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 16:55:46 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*str1;
	const char		*str2;
	size_t			n;
	size_t			len;

	str1 = dst;
	str2 = src;
	n = size;
	while (n-- && *str1)
		str1++;
	len = str1 - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(str2));
	while (*str2 != '\0')
	{
		if (n != 1)
		{
			*str1++ = *str2;
			n--;
		}
		str2++;
	}
	*str1 = 0;
	return (len + (str2 - src));
}
