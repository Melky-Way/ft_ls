/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:02:16 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:06:15 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_putnbr2(char *str, int i, int n)
{
	if (n == -2147483648)
	{
		str[i] = '8';
		n = n / 10;
		i--;
	}
	if (n < 0)
	{
		str[0] = ('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr2(str, i - 1, n / 10);
	str[i] = (n % 10 + '0');
	return (str);
}

static int		ft_size_of_n(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (10);
		n = -n;
	}
	if (n >= 10)
		return (ft_size_of_n(n / 10) + 1);
	else
		return (1);
}

char			*ft_itoa(int n)
{
	int		str_size;
	char	*str;

	str_size = ft_size_of_n(n);
	if (n < 0)
		str_size++;
	str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (str == NULL)
		return (NULL);
	str = ft_putnbr2(str, str_size - 1, n);
	str[str_size] = '\0';
	return (str);
}
