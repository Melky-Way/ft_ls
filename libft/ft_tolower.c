/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:49:16 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 15:25:31 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c - 'A' + 'a';
		return (c);
	}
	else
		return (c);
}

void	ft_tolower_str(char **str)
{
	int		i;

	i = -1;
	if (str == 0)
		return ;
	while ((*str)[++i] != 0)
		(*str)[i] = ft_tolower((*str)[i]);
}
