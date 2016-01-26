/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:26:14 by msoudan           #+#    #+#             */
/*   Updated: 2015/12/09 18:43:03 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_power(int nbr, int pwr)
{
	int		ret;

	ret = 1;
	while (pwr-- >= 1)
		ret *= nbr;
	return (ret);
}
