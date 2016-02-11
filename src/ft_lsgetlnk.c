/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetlnk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:25:36 by msoudan           #+#    #+#             */
/*   Updated: 2016/01/28 18:55:55 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_lsgetlnk(char *path)
{
	char			*tmp;
	char			buf[1024];
	ssize_t			len;

	if ((len = readlink(path, buf, sizeof(buf) - 1)) == -1)
		return (NULL);
	if ((tmp = ft_strnew(len + 4)) != NULL)
	{
		ft_memcpy(tmp, " -> ", 4);
		ft_memcpy(tmp + ft_strlen(tmp), buf, len);
	}
	return (tmp);
}
