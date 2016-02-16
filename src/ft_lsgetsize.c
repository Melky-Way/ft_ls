/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 21:56:02 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define MININT -2147483648
#define MAXINT 2147483647

int		ft_lsgetsize(int n)
{
	int i;

	i = 1;
	if (n < 0)
		n = (n == MININT) ? MAXINT : -n;
	while (n >= ft_power(10, i))
		i++;
	return (i);
}
