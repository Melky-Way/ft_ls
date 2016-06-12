/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 17:02:43 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define NAME tmpdata->d_name
#define T_DIR struct dirent
#define T_STAT struct stat

static int	ls_visibilityoptions(char *name, char option)
{
	if (option == 'A' && (!ft_strcmp(name, ".") || !ft_strcmp(name, "..")))
		return (0);
	if (option == 'a' || option == 'A')
		return (1);
	if (name[0] == '.')
		return (0);
	return (1);
}

static void	ft_ls_filldir(int *option, char *dir, char *name, t_dlist **data)
{
	char	*path;
	t_file	*tmpcontent;

	path = ft_lscreatepath(dir, name);
	if ((tmpcontent = ft_lsnewtfile(option, path, name)) != NULL)
		ft_dlist_tail(data, (void *)tmpcontent, sizeof(tmpcontent));
	free(path);
}

static char	*ft_lsbasename(char *name)
{
	int		i;

	i = ft_strlen(name) - 1;
	while (i >= 0 && name[i] && name[i] != '/')
		i--;
	return (name + i + 1);
}

int			ft_lsgetdatadir(int *option, char *dir, t_dlist **data)
{
	DIR		*fd;
	T_DIR	*tmpdata;

	fd = opendir(dir);
	if (fd == NULL || (tmpdata = readdir(fd)) == NULL)
		return (ft_lserror(ft_lsbasename(dir)));
	while (tmpdata != NULL)
	{
		if (ls_visibilityoptions(NAME, option[1]))
			ft_ls_filldir(option, dir, NAME, data);
		tmpdata = readdir(fd);
	}
	closedir(fd);
	return (data == NULL ? -1 : 0);
}

t_file		*ft_lsgetdata(int *option, char *dir)
{
	t_file	*tmpcontent;

	if ((tmpcontent = ft_lsnewtfile(option, dir, NULL)) != NULL)
		return (tmpcontent);
	else
		return (ft_lserrornull(dir));
}
