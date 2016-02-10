/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:29:07 by msoudan           #+#    #+#             */
/*   Updated: 2014/05/17 19:13:13 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_search_end(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void		*ft_line_filler(char *buff, char **line)
{
	char	*str;

	if (line[0][0] != 0)
	{
		str = ft_strjoin(*line, buff);
		free(*line);
		*line = str;
	}
	else
	{
		free(*line);
		*line = ft_strdup(buff);
	}
	free(buff);
	return (0);
}

static int		ft_search_line(char *buff, char **line, char **temp)
{
	int		n_found;

	if (temp != NULL)
		ft_memdel((void*)temp);
	if ((n_found = ft_search_end(buff)) >= 0)
	{
		*temp = ft_strsub(buff, n_found + 1, ft_strlen(buff) - n_found + 1);
		buff[n_found] = '\0';
		if (n_found == 0)
		{
			ft_memdel((void*)&buff);
			return (1);
		}
		ft_line_filler(buff, line);
		return (1);
	}
	ft_line_filler(buff, line);
	ft_memdel((void*)temp);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*temp = NULL;
	char			*buff;
	size_t			buff_len;

	*line = ft_strnew(1);
	if (temp != NULL && ft_search_line(ft_strdup(temp), line, &temp))
		return (1);
	else
		buff = ft_strnew(BUFF_SIZE + 1);
	while (BUFF_SIZE > 0 && (buff_len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[buff_len] = '\0';
		if ((ft_search_line(buff, line, &temp)))
			return (1);
		buff = ft_strnew(BUFF_SIZE + 1);
	}
	ft_memdel((void*)&buff);
	if (buff_len == 0 && (*line)[0] != 0)
		return (1);
	free(*line);
	if (buff_len == 0 && BUFF_SIZE > 0)
		return (0);
	return (-1);
}
