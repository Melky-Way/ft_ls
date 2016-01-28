/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:29 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 17:01:29 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (s == NULL || (copy = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len && s[start])
		copy[i++] = s[start++];
	copy[i] = '\0';
	return (copy);
}
