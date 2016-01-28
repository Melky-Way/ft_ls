/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:11 by msoudan           #+#    #+#             */
/*   Updated: 2013/11/20 17:01:12 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!n)
		return (1);
	while (*s1 && (*s1 == *s2) && n)
	{
		n--;
		if (n)
		{
			s1++;
			s2++;
		}
	}
	if (!n || (!*s1 && !*s2))
		return (1);
	else
		return (0);
}
