/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 16:35:38 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/06 16:35:40 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_arrjoin(char **array, char c, int option)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	i = -1;
	j = 0;
	while (array != NULL && array[++i] != NULL && i < option)
		j += ft_strlen(array[i]);
	j += i - 1;
	if (j > 0 && (tmp = ft_strnew(j)) != NULL)
	{
		i = -1;
		while (array != NULL && array[++i] != NULL && i < option)
		{
			if (ft_strlen(array[i]) > 0)
			{
				tmp = ft_strcat(tmp, array[i]);
				if (i + 1 != option)
					tmp[ft_strlen(tmp)] = c;
			}
		}
	}
	return (tmp);
}
