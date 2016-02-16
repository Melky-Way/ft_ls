/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgetdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 22:12:58 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define NAME tmpdata->d_name

static int			ls_visibilityoptions(char *name, char option)
{
	if (option == 'A' && (!ft_strcmp(name, ".") || !ft_strcmp(name, "..")))
		return (0);
	if (option == 'a' || option == 'A')
		return (1);
	if (name[0] == '.')
		return (0);
	return (1);
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
		if (ls_visibilityoptions(NAME, option[1]))
		{
			path = ft_lscreatepath(dir, NAME);
			if ((tmpcontent = ft_lsnewtfile(option, path, NAME)) != NULL)
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

static int			ft_lsisfile(int *option, char *dir)
{
	struct stat		sb;
	struct stat		sb2;

	if (lstat(dir, &sb))
		return (-1);
	stat(dir, &sb2);
	if (option[7])
		return (1);
	if (S_ISDIR(sb.st_mode))
		return (0);
	if (!option[2] && S_ISLNK(sb.st_mode) && S_ISDIR(sb2.st_mode))
		return (0);
	return (1);
}

int					ft_lsgetdata(int *option, char *dir, t_list **data)
{
	t_file			*tmpcontent;
	int				isfile;

	if ((isfile = ft_lsisfile(option, dir)) == -1)
		return (ft_lserror(dir));
	if (!isfile)
		return (ft_lsgetdatadir(option, dir, data));
	if ((tmpcontent = ft_lsnewtfile(option, dir, NULL)) != NULL)
		ft_lstpushback(data, (void *)tmpcontent, sizeof(tmpcontent));
	else
		return(ft_lserror(dir));
	return (0);
}


/*int					ft_lsgetdata(int *option, char *dir, t_list **data)
{
	t_file			*tmpcontent;
	struct stat		sb;

	if (lstat(dir, &sb) != 0)
		return (ft_lserror(dir));
	if (!option[7] && ((S_ISLNK(MODE) && !option[2]) || S_ISDIR(MODE)))
		return (ft_lsgetdatadir(option, dir, data));
	if ((S_ISLINK))
	if ((tmpcontent = ft_lsnewtfile(option, dir, NULL)) != NULL)
		ft_lstpushback(data, (void *)tmpcontent, sizeof(tmpcontent));
	else
		ft_lserror(dir);
	return (0);
}*/

/*int					ft_lsgetdata(int *option, char *dir, t_list **data)
{
	t_file			*tmpcontent;
	struct stat		sb;
	struct stat		sb2;

	if (lstat(dir, &sb))
		return (ft_lserror(dir));
	if (S_ISLNK(sb.stmode) && !stat(dir, &sb2) && S_ISDIR(sb2.st_mode))
		then fuck you
	if (!option[7] && S_ISDIR(sb.st_mode))
		return (ft_lsgetdatadir(option, dir, data));
	if ((tmpcontent = ft_lsnewtfile(option, dir, NULL)) != NULL)
		ft_lstpushback(data, (void *)tmpcontent, sizeof(tmpcontent));
	else
		ft_lserror(dir);
	return (0);
}*/