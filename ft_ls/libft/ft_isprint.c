/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:49:16 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 15:14:10 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int		ft_isprint_str(char *str)
{
	int		i;

	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] != 0 && ft_isprint(str[i]) == 1)
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}
