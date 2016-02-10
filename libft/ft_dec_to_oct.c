/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 16:47:45 by msoudan           #+#    #+#             */
/*   Updated: 2015/05/23 17:06:32 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_oct_to_dec(int nbr)
{
	int		cpy;
	int		pwr;
	int		ret;

	cpy = nbr;
	pwr = 0;
	ret = 0;
	while (cpy != 0)
	{
		ret += ((cpy % 10) * ft_power(8, pwr));
		cpy /= 10;
		pwr++;
	}
	return (ret);
}

int			ft_dec_to_oct(int nbr)
{
	int		cpy;
	int		pwr;
	int		ret;

	cpy = nbr;
	pwr = 0;
	ret = 0;
	while (cpy != 0)
	{
		ret += ((cpy % 8) * ft_power(10, pwr));
		cpy /= 8;
		pwr++;
	}
	return (ret);
}
