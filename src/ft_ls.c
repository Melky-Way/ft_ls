/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 13:54:27 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/10 16:22:25 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define TMP tmp->content
#define NAME (char *)(elem->content)

static int		link_or_dir(char *content)
{
	struct stat	sb;

	if (lstat(content, &sb) == 0 && S_ISLNK(sb.st_mode))
		return (0);
	return (1);
}

static void		print_dir(int *print, char *content)
{
	struct stat	sb;

	if (stat(content, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		if (*print > 1)
			ft_putchar('\n');
		if ((*print)++)
		{
			ft_putstr(content);
			ft_putendl(":");
		}
	}
}

/*
** Mode indicates wether or not ft_ls is dealing with args or dir contents.
** 1 == true ; 0 == false
*/

void			ft_ls(int print, int *option, t_list **directory, int mode)
{
	t_list		*elem;
	t_dlist		*data;

	if (mode)
		ft_ls_args(option, directory);
	elem = *directory;
	while (elem != NULL)
	{
		data = NULL;
		print_dir(&print, NAME);
		if (ft_lsgetdatadir(option, NAME, &data) != -1)
		{
			ft_lssortdata(option, &data);
			ft_lsprintdata(option, &data, link_or_dir(NAME));
			if (option[0] && !option[7])
				ft_lsrecursive(++print, option, NAME, &data);
			else if (*directory != NULL && data != NULL)
				ft_lscleardlist(&data);
		}
		elem = elem->next;
	}
	if (directory != NULL)
		ft_lstclear(directory);
}
