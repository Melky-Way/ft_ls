/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:38 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 17:01:38 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = (ft_strlen(s1) + ft_strlen(s2));
	if (total_len >= 2)
	{
		if ((s3 = (char *)malloc(sizeof(char *) * (total_len + 1))) == NULL)
			return (NULL);
		s3 = ft_strcat(ft_strcpy(s3, s1), s2);
		return (s3);
	}
	else
	{
		if ((s3 = (char *)malloc(sizeof(char *) + 1)) == NULL)
			return (NULL);
		s3[0] = '\0';
		return (s3);
	}
}
