/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:49:16 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 15:27:20 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 'a' + 'A';
		return (c);
	}
	else
		return (c);
}

void	ft_toupper_str(char **str)
{
	int		i;

	i = -1;
	if (str == 0)
		return ;
	while ((*str)[++i] != 0)
		(*str)[i] = ft_toupper((*str)[i]);
}
