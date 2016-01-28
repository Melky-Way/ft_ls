/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:54:35 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 16:54:35 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*pointer;

	pointer = s1;
	while (*s2 != '\0' && n)
	{
		*pointer = *s2;
		pointer++;
		s2++;
		n--;
	}
	while (n)
	{
		*pointer = '\0';
		pointer++;
		n--;
	}
	return (s1);
}
