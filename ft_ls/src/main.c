/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 23:45:58 by msoudan           #+#    #+#             */
/*   Updated: 2016/01/28 21:38:53 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	cpy = (argv[i] != NULL) ? argv[i] : ".";
	dir = ft_lstnew(cpy, (ft_strlen(cpy) + 1));
	if (argv[i] == NULL)
		return (dir);
	while (argv[++i] != NULL)
	{
		if ((cpy = ft_strdup(argv[i])) == NULL)
		{
			ft_lstclear(&dir);
			return (NULL);
		}
		ft_lstpushback(&dir, cpy, ft_strlen(argv[i] + 1));
	}
	sort_directories(&dir);
	return (dir);
}

static int		ft_printerror_option(char error)
{
	char		*str;

	str = "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]";
	ft_putstr_fd("ft_ls: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(error, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (-1);
}

/*
** About the int array named "option" :
** 0 = R ;
** 1 = a ;
** 2 = l ;
** 3 = r ;
** 4 = t ;
*/

static int		ft_getoptions(int *option, char **argv)
{
	int			i;
	int			j;
	char		*found;
	char		*list;

	i = 0;
	list = "Ralrt";
	while (argv[++i] != 0 && argv[i][0] == '-' && ft_strcmp(argv[i], "-"))
	{
		j = 0;
		if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		while (argv[i][++j] != 0)
		{
			if ((found = ft_strchr(list, argv[i][j])) != NULL)
				option[found - list] = (int)argv[i][j];
			else if (argv[i][j] == '1')
				option[2] = 0;
			else
				return (ft_printerror_option(argv[i][j]));
		}
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int			option[5] = {0};
	t_list		*directory;
	int			print;
	int			i;

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
		ft_ls(print, option, &directory);
	}
	return (0);
}
