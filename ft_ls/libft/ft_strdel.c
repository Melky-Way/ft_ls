/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:59:35 by msoudan           #+#    #+#             */
/*   Updated: 2014/03/22 16:07:41 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

void	ft_arrdel(char ***as)
{
	int		i;

	i = 0;
	if (as != NULL && (*as) != NULL)
	{
		while ((*as)[i] != NULL)
		{
			free((*as)[i]);
			i++;
		}
		free(*as);
		(*as) = NULL;
	}
}
