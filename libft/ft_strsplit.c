/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:02:08 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:10:36 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fillarray(char const *s, char c, size_t nbr, char **array)
{
	size_t		len;
	size_t		i;

	len = 0;
	i = 0;
	while (nbr > i)
	{
		if (*s && *s != c)
			len++;
		else if (len)
		{
			array[i] = ft_strsub(s - len, 0, len);
			i++;
			len = 0;
		}
		s++;
	}
	array[nbr] = NULL;
}

static size_t	ft_elemnbr(char const *s, char c)
{
	size_t		nbr;

	nbr = 0;
	while (*s)
	{
		if (*s != c)
		{
			nbr++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (nbr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		nbr;
	char		**array;
	char		*str;

	if (s == NULL || *s == 0)
	{
		array = (char **)malloc(sizeof(char *) * 1);
		array[0] = NULL;
		return (array);
	}
	str = ft_strtrim(s);
	nbr = ft_elemnbr((char const *)str, c);
	if ((array = (char **)malloc(sizeof(char *) * (nbr + 1))) == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_fillarray((char const *)str, c, nbr, array);
	free(str);
	return (array);
}
