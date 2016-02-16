/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lserror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:36:01 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 21:37:00 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				delete_elem(t_list **dir, t_list **tmp, t_list **prev)
{
	t_list			*del;

	if ((del = *tmp) == *dir)
		*dir = (*dir)->next;
	*tmp = (*tmp)->next;
	if (*prev != NULL)
		(*prev)->next = *tmp;
	if (del->content != NULL)
	{
		free(del->content);
		del->content = NULL;
	}
	free(del);
	del = NULL;
}

int					ft_lserrorlist(t_list **dir)
{
	t_list			*tmp;
	t_list			*prev;
	struct stat		buf;

	if ((tmp = *dir) != NULL)
	{
		prev = NULL;
		while (tmp != NULL)
		{
			if (lstat((char *)tmp->content, &buf) == -1)
			{
				ft_lserror((char *)tmp->content);
				delete_elem(dir, &tmp, &prev);
			}
			else
			{
				prev = tmp;
				tmp = tmp->next;
			}
		}
		return (0);
	}
	return (-1);
}

void				*ft_lserrornull(char *name)
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	perror(name);
	return (NULL);
}

int					ft_lserror(char *name)
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	perror(name);
	return (-1);
}
