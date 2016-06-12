/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsrecursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 17:18:58 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/09 22:51:26 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define NAME ((t_file *)tmp->content)->name
#define NOT_CURRENT_NOR_PARENT (ft_strcmp(NAME, ".") && ft_strcmp(NAME, ".."))

char		*ft_lscreatepath(char *str1, char *str2)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (ret)
	{
		ft_strcat(ret, str1);
		ret[ft_strlen(str1)] = '/';
		ft_strcat(ret, str2);
	}
	return (ret);
}

void		ft_lsrecursive(int print, int *op, char *old, t_dlist **data)
{
	t_list	*dir;
	t_dbl	*tmp;
	char	*name;

	dir = NULL;
	if (*data == NULL || (tmp = (*data)->head) == NULL)
		return ;
	while (tmp != NULL)
	{
		if (((t_file *)tmp->content)->type == 'd' && NOT_CURRENT_NOR_PARENT)
		{
			name = ft_lscreatepath(old, NAME);
			ft_lstpushback(&dir, ft_strdup(name), ft_strlen(name));
			free(name);
		}
		tmp = tmp->next;
	}
	ft_lscleardlist(data);
	ft_ls(print, op, &dir, 0);
}
