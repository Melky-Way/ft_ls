/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 18:26:41 by msoudan           #+#    #+#             */
/*   Updated: 2013/12/17 18:26:41 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function create an array of arrays of int. The file given by argv[1]
** is cut by get_next_line, the line created is sent in a function that
** makes it into an array of int.
*/

int		**ft_make_array(int **array, char *argv)
{
	char	*line;
	size_t	i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_memdel((void *)&line);
		i++;
	}
	array = (int **)malloc(sizeof(array) * (i + 1));
	close(fd);
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		array[i++] = ft_str_array(line);
		ft_memdel((void *)&line);
	}
	close(fd);
	return (array);
}
