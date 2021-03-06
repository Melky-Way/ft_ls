/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 23:45:58 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/12 21:09:40 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define ARG argv[i][j]

static void		sort_directories(t_list **dir)
{
	t_list		*elem1;
	t_list		*elem2;

	if ((elem1 = *dir) == NULL)
		return ;
	elem2 = (*dir)->next;
	while (elem1 != NULL && (elem2 = elem1->next) != NULL)
	{
		if (ft_strcmp((char *)elem1->content, (char *)elem2->content) > 0)
		{
			ft_lst_swap(elem1, elem2);
			elem1 = *dir;
		}
		else
			elem1 = elem1->next;
	}
}

static t_list	*ft_getdirectories(char **argv)
{
	int			i;
	t_list		*dir;
	char		*cpy;

	i = 0;
	if (argv[i] == NULL)
		return ((dir = ft_lstnew(ft_strdup("."), 2)));
	dir = NULL;
	while (argv[i] != NULL)
	{
		if (!ft_strcmp(argv[i], "") || (cpy = ft_strdup(argv[i])) == NULL)
		{
			if (!ft_strcmp(argv[i], ""))
				ft_putendl_fd("ls: fts_open: No such file or directory",
					STDERR_FILENO);
			ft_lstclear(&dir);
			dir = NULL;
			return (NULL);
		}
		ft_lstpushback(&dir, cpy, ft_strlen(argv[i] + 1));
		i++;
	}
	sort_directories(&dir);
	return (dir);
}

static int		ft_lsgetoptionsalt(int *option, char arg)
{
	if (arg == '1')
	{
		option[2] = 0;
		option[10] = 0;
		option[11] = 0;
	}
	else if (arg == 'U' || arg == 'c')
		option[5] = (int)arg;
	else if (arg == 'F')
		option[8] = (int)arg;
	else if (arg == 'A')
		option[1] = !option[1] ? (int)arg : option[1];
	else
		return (0);
	return (1);
}

static int		ft_getoptions(int *option, char **argv)
{
	int			i;
	int			j;
	char		*found;
	char		*list;

	i = 0;
	list = "RalrtuSdpfogT";
	while (argv[++i] != 0 && argv[i][0] == '-' && ft_strcmp(argv[i], "-"))
	{
		j = 0;
		if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		while (argv[i][++j] != 0)
		{
			if ((found = ft_strchr(list, ARG)) != NULL)
				option[found - list] = (int)ARG;
			else if (!ft_lsgetoptionsalt(option, ARG))
				return (ft_printerror_option(ARG));
		}
		option[1] = option[9] ? (int)'a' : option[1];
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int			option[13];
	t_list		*directory;
	int			print;
	int			i;

	ft_memset(option, 0, sizeof(option));
	directory = NULL;
	i = 1;
	if (argc > 1 && (i = ft_getoptions(option, argv)) == -1)
		return (-1);
	i = (i > 1) ? i : 1;
	if ((directory = ft_getdirectories(argv + i)) == NULL)
		return (-1);
	else
	{
		print = (ft_lstsize(directory) > 1) ? 1 : 0;
		if (ft_lserrorlist(&directory) != -1)
			ft_ls(print, option, &directory, 1);
	}
	return (0);
}
