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

#define MININT -2147483648
#define MAXINT 2147483647
#define TMP ((t_file *)tmp->content)

static int		ft_lsgetsize(int n)
{
	int i;

	i = 1;
	if (n < 0)
		n = (n == MININT) ? MAXINT : -n;
	while (n >= ft_power(10, i))
		i++;
	return (i);
}

static void		ft_lsgetspaces(int *array, t_list **data)
{
	t_list		*tmp;
	int			i;

	tmp = (t_list *)*data;
	while (tmp != NULL)
	{
		array[0] = array[0] < TMP->links ? TMP->links : array[0];
		i = (int)ft_strlen(TMP->owner);
		array[1] = array[1] < i ? i : array[1];
		i = (int)ft_strlen(TMP->group);
		array[2] = array[2] < i ? i : array[2];
		array[3] = array[3] < TMP->size ? TMP->size : array[3];
		tmp = tmp->next;
	}
	array[0] = ft_lsgetsize(array[0]);
	array[3] = ft_lsgetsize(array[3]);
}

static void		ft_lsprintdate(time_t date)
{
	int			i;
	char		*str;
	time_t		now;

	i = 3;
	str = ctime(&date);
	now = time(NULL);
	ft_putchar(' ');
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

static void		ft_lsprintlong(int *option, t_list **data, int dir)
{
	t_list		*tmp;
	int			array[4] = {0, 0, 0, 0};

	ft_lsgetspaces(array, data);
	if ((tmp = *data) != NULL && (ft_lstsize(tmp) > 1 || dir))
	{
		ft_putstr("total ");
		ft_putendl(ft_itoa(ft_lsblkcnt(tmp)));
	}
	while (tmp != NULL)
	{
		ft_putchar(TMP->type);
		ft_putstr(TMP->access);
		ft_printspaces(1 + (array[0] - ft_lsgetsize(TMP->links)));
		ft_putnbr(TMP->links);
		ft_putstr(" ");
		ft_putstr(TMP->owner);
		ft_printspaces(array[1] - ft_strlen(TMP->owner));
		ft_putstr("  ");
		ft_putstr(TMP->group);
		ft_printspaces(array[2] - ft_strlen(TMP->group));
		ft_printspaces(2 + (array[3] - ft_lsgetsize(TMP->size)));
		ft_putnbr(TMP->size);
		ft_lsprintdate(TMP->date);
		ft_putstr(TMP->name);
		if (option[8] && TMP->type == 'd')
			ft_putchar('/');
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void			ft_lsprintdata(int *option, t_list **data, int dir)
{
	t_list		*tmp;

	tmp = *data;
	if (option[2] == 108)
		ft_lsprintlong(option, &tmp, dir);
	else
	{
		while (tmp != NULL)
		{
			ft_putstr(TMP->name);
			if (option[8] && TMP->type == 'd')
				ft_putchar('/');
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}