/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 10:49:30 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/03 11:58:03 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include "ft_colors.h"

/*
** write readlink exit
*/
# include <unistd.h>

/*
** opendir readdir closedir
*/
# include <sys/types.h>
# include <dirent.h>

/*
** stat lstat
*/
# include <sys/stat.h>
# include <unistd.h>

/*
** getpwuid
*/
# include <pwd.h>

/*
** getgrgid
*/
# include <grp.h>

/*
** time ctime
*/
# include <time.h>

/*
** malloc free
*/
# include <stdlib.h>

/*
** perror
*/
# include <stdio.h>

/*
** strerror
*/
# include <string.h>

/*
** errno
*/
# include <errno.h>

/*
** getxattr
*/
#include <sys/xattr.h>

typedef struct		s_file
{
	char			*name;
	char			*lnk;
	char			type;
	char			*access;
	int				links;
	char			*owner;
	char			*group;
	int				size;
	int				blkcnt;
	time_t			date;
}					t_file;

t_list				*ft_lstmergesort(t_list *a, int n, \
					int (*f)(t_list *a, t_list *b));
char				*usernamefromid(uid_t uid);
char				*groupnamefromid(gid_t gid);
char				*ft_lscreatepath(char *str1, char *str2);
void				ft_printspaces(int n);
int					ft_lsgetdata(int *option, char *directory, t_list **data);
void				ft_lssortdata(int *option, t_list **data);
void				ft_lsprintdata(int *option, t_list **data, int dir);
void				ft_ls(int print, int *option, t_list **directory);
void				ft_lsrecursive(int pr, int *op, char *old, t_list **data);
void				ft_lsclearlist(t_list **data);
int					ft_lsblkcnt(t_list *data);
void				delete_elem(t_list **dir, t_list **tmp, t_list **prev);
int					ft_lserrorlist(t_list **dir);
void				*ft_lserrornull(char *name);
int					ft_lserror(char *name);
char				*ft_lsgetlnk(char *path);
t_file				*ft_lsnewtfile(int *option, char *path, char *name);
void				ft_lsgetspaces(int *array, t_list **data);
int					ft_lsgetsize(int n);
int					main(int argc, char **argv);

#endif
