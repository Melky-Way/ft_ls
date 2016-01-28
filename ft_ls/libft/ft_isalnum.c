/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:08:09 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 15:05:47 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_isalnum_str(char *str)
{
	int		i;

	i = 0;
	if (str && str[i] == 0)
		return (0);
	while (str[i] != 0 && ft_isalnum(str[i]) == 1)
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}
