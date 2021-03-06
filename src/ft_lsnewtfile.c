/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnewtfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 21:07:26 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define IS_LONG (option[2] || option[10] || option[11])
#define NO_USRX (access[2] == '-' || access[2] == 'S')
#define NO_GRPX (access[5] == 'S' || access[5] == '-')
#define XATTR_SIZE 10000
#define BIRTH_NANO buf.st_birthtimespec.tv_nsec
#define ATIME_NANO buf.st_atimespec.tv_nsec
#define CTIME_NANO buf.st_ctimespec.tv_nsec
#define MTIME_NANO buf.st_mtimespec.tv_nsec

static char		ft_lsidentifytype(mode_t st_mode)
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
	else if (S_ISWHT(st_mode))
		return ('w');
	else
		return ('-');
}

static char		ft_lsxattr(char *path)
{
	char		buf[XATTR_SIZE];
	ssize_t		len;

	if (path && (len = listxattr(path, buf, XATTR_SIZE, XATTR_NOFOLLOW)) > 0)
		return ('@');
	return (' ');
}

static char		*ft_lsidentifyaccess(char *path, mode_t st_mode)
{
	char		*access;
	int			type;

	access = ft_strnew(10);
	type = ft_dec_to_oct(st_mode & S_IRWXU) / 100;
	access[0] = (type >= 4) ? 'r' : '-';
	access[1] = (type > 1 && type != 4 && type != 5) ? 'w' : '-';
	access[2] = (type % 2 != 0) ? 'x' : '-';
	if (st_mode & S_ISUID)
		access[2] = access[2] == 'x' ? 's' : 'S';
	type = ft_dec_to_oct(st_mode & S_IRWXG) / 10;
	access[3] = (type >= 4) ? 'r' : '-';
	access[4] = (type > 1 && type != 4 && type != 5) ? 'w' : '-';
	access[5] = (type % 2 != 0) ? 'x' : '-';
	if (st_mode & S_ISGID)
		access[5] = access[5] == 'x' ? 's' : 'S';
	type = ft_dec_to_oct(st_mode & S_IRWXO);
	access[6] = (type >= 4) ? 'r' : '-';
	access[7] = (type > 1 && type != 4 && type != 5) ? 'w' : '-';
	access[8] = (type % 2 != 0) ? 'x' : '-';
	if (st_mode & S_ISVTX)
		access[8] = (NO_USRX && NO_GRPX) ? 'T' : 't';
	access[9] = ft_lsxattr(path);
	return (access);
}

static t_file	*ft_lsprohibited(int *option, char *name, t_file *elem)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 13)
		j += option[i++] ? 1 : 0;
	if (j)
	{
		free(elem);
		return ((t_file *)ft_lserrornull(name));
	}
	else
	{
		elem->name = ft_strdup(name);
		elem->access = NULL;
		elem->owner = NULL;
		elem->group = NULL;
		elem->lnk = NULL;
		return (elem);
	}
}

t_file			*ft_lsnewtfile(int *option, char *path, char *name)
{
	t_file		*elem;
	struct stat	buf;

	if ((elem = (t_file *)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	if (lstat(path, &buf) == -1)
		return (ft_lsprohibited(option, name, elem));
	elem->type = ft_lsidentifytype(buf.st_mode);
	elem->name = name == NULL ? ft_strdup(path) : ft_strdup(name);
	elem->lnk = (elem->type == 'l' && IS_LONG) ? ft_lsgetlnk(path) : NULL;
	elem->access = ft_lsidentifyaccess(path, buf.st_mode);
	elem->blkcnt = buf.st_blocks;
	elem->links = buf.st_nlink;
	elem->owner = option[11] ? NULL : ft_strdup(usernamefromid(buf.st_uid));
	elem->group = option[10] ? NULL : ft_strdup(groupnamefromid(buf.st_gid));
	elem->size = buf.st_size;
	if (option[5] == 'U' || option[5] == 'u')
		elem->date = option[5] == 'U' ? buf.st_birthtime : buf.st_atime;
	else if (option[5] == 'c' || !option[5])
		elem->date = option[5] == 'c' ? buf.st_ctime : buf.st_mtime;
	if (option[5] == 'U' || option[5] == 'u')
		elem->nano = option[5] == 'U' ? BIRTH_NANO : ATIME_NANO;
	else if (option[5] == 'c' || !option[5])
		elem->nano = option[5] == 'c' ? CTIME_NANO : MTIME_NANO;
	return (elem);
}
