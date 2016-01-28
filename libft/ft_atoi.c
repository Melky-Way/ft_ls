/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:22:18 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:11:11 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int		number;
	int		is_minus;
	int		i;

	number = 0;
	is_minus = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == 43 || str[i] == 45))
		is_minus = (str[i++] == 45) ? 1 : 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (is_minus)
		return (-number);
	return (number);
}
