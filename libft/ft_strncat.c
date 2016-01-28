/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:05:16 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 15:05:17 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;
	char	*pointer;

	a = 0;
	b = 0;
	pointer = s1;
	while (s1[a])
		a++;
	while (s2[b] && (b != n))
	{
		s1[a] = s2[b];
		a++;
		b++;
	}
	s1[a] = 0;
	return (pointer);
}
