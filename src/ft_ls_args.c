/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:03:16 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 16:58:56 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define DIR ((t_file *)(tmp->content))->name
#define FILE ((t_file *)tmp->content)
#define HEAD (*lst)->head
#define TAIL (*lst)->tail
#define LNK_BUT_DIR (tmp->type == 'l' && S_ISDIR(buf.st_mode))

static void		ft_data_to_dir(t_list **directory, t_dlist **data)
{
	t_dbl		*tmp;

	if (*data == NULL)
		return ;
	tmp = (*data)->head;
	while (tmp != NULL)
	{
		ft_lstpushback(directory, ft_strdup(DIR), ft_strlen(DIR));
		tmp = tmp->next;
	}
	ft_lscleardlist(data);
}

static void		ft_filldlist(int *option, t_dlist **file, t_dlist **dir, \
				t_list **directory)
{
	t_file		*tmp;
	t_list		*elem;
	struct stat	buf;

	elem = *directory;
	while (elem != NULL)
	{
		if ((tmp = ft_lsgetdata(option, (char *)elem->content)) != NULL)
		{
			stat(tmp->name, &buf);
			if ((tmp->type == 'd' && !option[7]) || (LNK_BUT_DIR && !option[2]))
				ft_dlist_tail(dir, (void *)tmp, sizeof(tmp));
			else
				ft_dlist_tail(file, (void *)tmp, sizeof(tmp));
		}
		elem = elem->next;
	}
}

void			ft_ls_args(int *option, t_list **directory)
{
	t_dlist		*dir;
	t_dlist		*file;

	dir = NULL;
	file = NULL;
	ft_filldlist(option, &file, &dir, directory);
	ft_lssortdata(option, &file);
	ft_lssortdata(option, &dir);
	ft_lsprintdata(option, &file, 0);
	if (file != NULL && dir != NULL)
		ft_putchar('\n');
	ft_lscleardlist(&file);
	ft_lstclear(directory);
	ft_data_to_dir(directory, &dir);
}
