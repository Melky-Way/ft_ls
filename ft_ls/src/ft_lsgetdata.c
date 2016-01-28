/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/01/28 18:30:30 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			ft_lsidentifytype(mode_t st_mode)
{
	if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISLNK(st_mode))
		return ('l');
	else
		return ('-');
}

static char			*ft_lsidentifyaccess(mode_t st_mode)
{
	char			*access;
	int				type;

	access = ft_strnew(9);
	type = ft_dec_to_oct(st_mode & S_IRWXU) / 100;
	access[0] = (type >= 4) ? 'r' : '-';
	access[1] = (type > 1 && type != 4 && type != 5) ? 'w' : '-';
	access[2] = (type%2 != 0) ? 'x' : '-';
	type = ft_dec_to_oct(st_mode & S_IRWXG) / 10;
	access[3] = (type >= 4) ? 'r' : '-';
	access[4] = (type > 1 && type != 4 && type != 5) ? 'w' : '-';
	access[5] = (type%2 != 0) ? 'x' : '-';
	type = ft_dec_to_oct(st_mode & S_IRWXO);
	access[6] = (type >= 4) ? 'r' : '-';
	access[7] = (type > 1 && type != 4 && type != 5) ? 'w' : '-';
	access[8] = (type%2 != 0) ? 'x' : '-';
	return (access);
}

static t_file		*ft_lsnewtfile(int lf, char *path, char *name)
{
	t_file			*elem;
	struct stat		buf;

	if (lstat(path, &buf) == -1)
		return (NULL);
	if ((elem = (t_file *)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	elem->type = ft_lsidentifytype(buf.st_mode);
	elem->name = ft_lsgetname(lf, elem->type, path, name);
	elem->access = lf ? ft_lsidentifyaccess(buf.st_mode) : NULL;
	elem->blkcnt = buf.st_blocks;
	elem->links = lf ? buf.st_nlink : 0;
	elem->owner = lf ? ft_strdup(userNameFromId(buf.st_uid)) : NULL;
	elem->group = lf ? ft_strdup(groupNameFromId(buf.st_gid)) : NULL;
	elem->size = lf ? buf.st_size : 0;
	elem->date = buf.st_mtimespec.tv_sec;
	return (elem);
}

static int			ft_lsgetdatadir(int *option, char *dir, t_list **data)
{
	DIR				*fd;
	struct dirent	*tmpdata;
	t_file			*tmpcontent;
	char			*path;

	if ((fd = opendir(dir)) == NULL || (tmpdata = readdir(fd)) == NULL)
		return (ft_lserror(dir));
	while (tmpdata != NULL)
	{
		if ((!option[1] && tmpdata->d_name[0] != '.') || option[1])
		{
			path = ft_lscreatepath(dir, tmpdata->d_name);
			tmpcontent = ft_lsnewtfile(option[2], path, tmpdata->d_name);
			ft_lstpushback(data, (void *)tmpcontent, sizeof(tmpcontent));
			free(path);
		}
		tmpdata = readdir(fd);
	}
	closedir(fd);
	if (*data == NULL)
		return (-1);
	return (0);
}

int					ft_lsgetdata(int *option, char *dir, t_list **data)
{
	t_file			*tmpcontent;
	struct stat		sb;

	if (stat(dir, &sb) == 0 && S_ISDIR(sb.st_mode))
		return (ft_lsgetdatadir(option, dir, data));
	if ((tmpcontent = ft_lsnewtfile(option[2], dir, NULL)) != NULL)
		ft_lstpushback(data, (void *)tmpcontent, sizeof(tmpcontent));
	else
		ft_lserror(dir);
	return (0);
}
