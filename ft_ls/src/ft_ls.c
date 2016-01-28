/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 13:54:27 by msoudan           #+#    #+#             */
/*   Updated: 2015/06/08 17:47:46 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

static void		ft_split_list(t_list **dir, t_list **file)
{
	struct stat	sb;
	t_list		*tmp;
	t_list		*del;
	t_list		*prev;

	tmp = *dir;
	while (tmp != NULL)
	{
		if (stat((char *)tmp->content, &sb) == 0 && !S_ISDIR(sb.st_mode))
		{
			ft_lstpushback(file, tmp->content, tmp->content_size);
			del = tmp;
			if (del == *dir)
				*dir = (*dir)->next;
			tmp = tmp->next;
			if (prev != NULL)
				prev->next = tmp;
			free(del);
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
	ft_split_list(directory, &file);
	if (file == NULL)
		return ;
	elem = file;
	data = NULL;
	while (elem != NULL)
	{
		ft_lsgetdata(option, (char *)elem->content, &data);
		elem = elem->next;
	}
	ft_lssortdata(option[3], option[4], &data);
	ft_lsprintdata(option[2], &data);
	ft_lsclearlist(&data);
	ft_lstclear(&file);
	if (directory != NULL)
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
			ft_lssortdata(option[3], option[4], &data);
			ft_lsprintdata(option[2], &data);
			if (option[0])
				ft_lsrecursive(++print, option, (char *)elem->content, &data);
			else if (*directory != NULL)
				ft_lsclearlist(&data);
		}
		elem = elem->next;
	}
	ft_lstclear(directory);
}
