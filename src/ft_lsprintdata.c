/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprintdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:16:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/02 21:56:02 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define TMP ((t_file *)tmp->content)

static void		ft_lsprintdate(time_t date, int mode)
{
	int			i;
	char		*str;
	time_t		now;

	i = mode ? 3 : 2;
	str = ctime(&date);
	now = time(NULL);
	if (mode)
	{
		while (str[i] && str[i] != '\n')
			ft_putchar(str[i++]);
		ft_putchar(' ');
		return ;
	}
	while (str[i++] && i != 16 && str[i] != '\n')
	{
		if (i == 11 && ((now - date) >= 15768000 || date > now))
		{
			i += 8;
			while (str[i + 1] && ft_isspace(str[i + 1]))
				i++;
		}
		ft_putchar(str[i]);
	}
	ft_putchar(' ');
}

static void		ft_lsnameoptions(int option, char type, char *acc)
{
	if (option && type == 'd')
		ft_putchar('/');
	if (option == 'F')
	{
		if (type == 'p')
			ft_putchar('|');
		if (type == 'l')
			ft_putchar('@');
		if (type == 's')
			ft_putchar('=');
		if (type == 'w')
			ft_putchar('%');
		else if (type == '-' && acc != NULL && \
			(acc[2] == 'x' || acc[5] == 'x' || acc[8] == 'x'))
			ft_putchar('*');
	}
}

static void		ft_lsprintlongcore(int *option, t_list *tmp, int array[])
{
	ft_putchar(TMP->type);
	ft_putstr(TMP->access);
	ft_printspaces(1 + (array[0] - ft_lsgetsize(TMP->links)));
	ft_putnbr(TMP->links);
	ft_putstr(" ");
	ft_putstr(TMP->owner);
	if (!option[11])
		ft_printspaces(2 + array[1] - ft_strlen(TMP->owner));
	ft_putstr(TMP->group);
	if (!option[10] || (option[10] && option[11]))
		ft_printspaces(2 + array[2] - ft_strlen(TMP->group));
	ft_printspaces((array[3] - ft_lsgetsize(TMP->size)));
	ft_putnbr(TMP->size);
	ft_lsprintdate(TMP->date, option[12]);
	ft_putstr(TMP->name);
	ft_lsnameoptions(option[8], TMP->type, TMP->access);
	ft_putstr(TMP->lnk);
	ft_putchar('\n');
}

static void		ft_lsprintlong(int *option, t_list **data, int dir)
{
	int			array[4];
	t_list		*tmp;

	ft_memset(array, 0, sizeof(array));
	ft_lsgetspaces(array, data);
	if ((tmp = *data) != NULL && (ft_lstsize(tmp) > 1 || dir))
	{
		ft_putstr("total ");
		ft_putendl(ft_itoa(ft_lsblkcnt(tmp)));
	}
	while (tmp != NULL)
	{
		ft_lsprintlongcore(option, tmp, array);
		tmp = tmp->next;
	}
}

void			ft_lsprintdata(int *option, t_list **data, int dir)
{
	t_list		*tmp;

	tmp = *data;
	if (option[2] || option[10] || option[11])
		ft_lsprintlong(option, &tmp, dir);
	else
	{
		while (tmp != NULL)
		{
			ft_putstr(TMP->name);
			ft_lsnameoptions(option[8], TMP->type, TMP->access);
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}
