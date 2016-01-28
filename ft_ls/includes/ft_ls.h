/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 10:49:30 by msoudan           #+#    #+#             */
/*   Updated: 2016/01/28 21:39:43 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"

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


typedef struct		s_file
{
	char			*name;
	char			type;
	char			*access;
	int				links;
	char			*owner;
	char			*group;
	int				size;
	int				blkcnt;
	time_t			date;
}					t_file;

char				*userNameFromId(uid_t uid);
char				*groupNameFromId(gid_t gid);
char				*ft_lscreatepath(char *str1, char *str2);
void				ft_printspaces(int n);
int					ft_lsgetdata(int *option, char *directory, t_list **data);
void				ft_lssortdata(int reverse, int sortbytime, t_list **data);
void				ft_lsprintdata(int longformat, t_list **data, int dir);
void				ft_ls(int print, int *option, t_list **directory);
void				ft_lsrecursive(int pr, int *op, char *old, t_list **data);
void				ft_lsclearlist(t_list **data);
int					ft_lsblkcnt(t_list *data);
int					ft_lserror(char *name);
char				*ft_lsgetname(int lf, char type, char *path, char *name);
int					main(int argc, char **argv);

#endif
