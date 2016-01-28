/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:49:16 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 17:22:33 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_isdigit_str(char *str)
{
	int		i;

	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] != 0 && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
