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
	int i = 0;

	if ((fd = opendir(dir)) == NULL || (tmpdata = readdir(fd)) == NULL)
		return (ft_lserror(dir));
	while (tmpdata != NULL)
	{
		if (i++ > 15000)
			printf("%i.\n", i);
		/*if ((!option[1] && tmpdata->d_name[0] != '.') || option[1])*/
		if (ls_visibilityoptions(tmpdata->d_name, option[1]))
		{
			path = ft_lscreatepath(dir, tmpdata->d_name);
			tmpcontent = ft_lsnewtfile(option, path, tmpdata->d_name);
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

	if (stat(dir, &sb) == 0 && S_ISDIR(sb.st_mode) && !option[7])
		return (ft_lsgetdatadir(option, dir, data));
	if ((tmpcontent = ft_lsnewtfile(option, dir, NULL)) != NULL)
		ft_lstpushback(data, (void *)tmpcontent, sizeof(tmpcontent));
	else
		ft_lserror(dir);
	return (0);
}
