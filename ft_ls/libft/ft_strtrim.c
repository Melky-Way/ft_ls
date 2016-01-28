/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:50 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 17:01:50 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		len;

	start = 0;
	if (s == NULL)
		return (NULL);
	while (ft_isspace(s[start]) && s[start])
		start++;
	if (!s[start])
		return (ft_strnew(0));
	len = (unsigned int)ft_strlen(s) - 1;
	while (ft_isspace(s[len]) && len)
		len--;
	len = len - start + 1;
	if (len > 0)
		return (ft_strsub(s, (unsigned int)start, (size_t)len));
	return (ft_strdup(s));
}
