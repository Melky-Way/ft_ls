/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:13:52 by msoudan           #+#    #+#             */
/*   Updated: 2015/11/23 15:13:55 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(char *str)
{
	char		*big;
	int			i;

	i = 0;
	if (str != NULL)
	{
		big = *str == '-' ? "2147483648" : "2147483647";
		if ((*str == '-' && ft_isdigit_str(++str)) || ft_isdigit_str(str))
		{
			if (ft_strlen(str) > 10)
				return (0);
			if (ft_strlen(str) < 10)
				return (1);
		}
		while (str[i] != 0)
		{
			if (str[i] > big[i])
				return (0);
			i++;
		}
	}
	return (1);
}
