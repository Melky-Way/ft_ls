/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:40:46 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 15:45:02 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n' ||
		c == ' ')
		return (1);
	else
		return (0);
}

int		ft_isspace_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
