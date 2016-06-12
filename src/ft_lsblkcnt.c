/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsblkcnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 14:44:45 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/08 18:49:29 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_lsblkcnt(t_dbl *data)
{
	int		size;

	size = 0;
	while (data != NULL)
	{
		size += ((t_file *)data->content)->blkcnt;
		data = data->next;
	}
	return (size);
}
