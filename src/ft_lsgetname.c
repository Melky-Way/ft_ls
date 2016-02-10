/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:25:36 by msoudan           #+#    #+#             */
/*   Updated: 2016/01/28 18:55:55 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*get_tmpname(char *path, char *name, ssize_t len)
{
	char			*ret;
	char			*tmp;
	size_t			siz;

	siz = (name == NULL) ? ft_strlen(path) : ft_strlen(name);
	ret = ft_strnew(siz + len);
	tmp = name != NULL ? ft_memcpy(ret, name, siz) : ft_memcpy(ret, path, siz);
	ft_memcpy(tmp + siz, " -> ", 4);
	return (ret);
}

char				*ft_lsgetname(int lf, char type, char *path, char *name)
{
	char			*tmp;
	char			buf[1024];
	ssize_t			len;

	if (lf && type == 'l')
	{
		if ((len = readlink(path, buf, sizeof(buf)-1)) != -1)
		{
			tmp = get_tmpname(path, name, len + 4);
			ft_memcpy(tmp + ft_strlen(tmp), buf, len);
			return (tmp);
		}
		return (NULL);
	}
	tmp = name == NULL ? ft_strdup(path) : ft_strdup(name);
	return (tmp);
}
