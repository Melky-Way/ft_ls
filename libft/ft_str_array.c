/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 18:26:56 by msoudan           #+#    #+#             */
/*   Updated: 2013/12/17 18:26:57 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_str_array(char *line)
{
	int		i;
	int		*array;
	char	**temp;

	i = 0;
	temp = ft_strsplit(line, ',');
	while (temp[i] != NULL)
		i++;
	array = (int*)malloc(sizeof(int *) * (i + 1));
	i = 0;
	while (temp[i] != NULL)
	{
		array[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	free(temp);
	return (array);
}
