/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 13:54:27 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 22:14:37 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define TMP tmp->content

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

static void		ft_split_list(int *opt, t_list **dir, t_list **file)
{
	struct stat	sb;
	t_list		*tmp;
	t_list		*prev;

	tmp = *dir;
	prev = NULL;
	while (tmp != NULL)
	{
		if (opt[7] || (!stat((char *)TMP, &sb) && !S_ISDIR(sb.st_mode)))
		{
			ft_lstpushback(file, TMP, tmp->content_size);
			TMP = NULL;
			delete_elem(dir, &tmp, &prev);
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

static void		ft_ls_file(int *option, t_list **directory)
{
	t_list		*file;
	t_list		*data;
	t_list		*elem;

	file = NULL;
	ft_split_list(option, directory, &file);
	if (file == NULL)
		return ;
	elem = file;
	data = NULL;
	while (elem != NULL)
	{
		ft_lsgetdata(option, (char *)elem->content, &data);
		elem = elem->next;
	}
	ft_lssortdata(option, &data);
	ft_lsprintdata(option, &data, 0);
	ft_lsclearlist(&data);
	ft_lstclear(&file);
	if (*directory != NULL)
		ft_putchar('\n');
}

void			ft_ls(int print, int *option, t_list **directory)
{
	t_list		*elem;
	t_list		*data;

	ft_ls_file(option, directory);
	elem = *directory;
	while (elem != NULL)
	{
		data = NULL;
		print_dir(&print, (char *)elem->content);
		if (ft_lsgetdata(option, (char *)elem->content, &data) != -1)
		{
			ft_lssortdata(option, &data);
			ft_lsprintdata(option, &data, link_or_dir((char *)elem->content));
			if (option[0] && !option[7])
				ft_lsrecursive(++print, option, (char *)elem->content, &data);
			else if (*directory != NULL)
				ft_lsclearlist(&data);
		}
		elem = elem->next;
	}
	ft_lstclear(directory);
}
